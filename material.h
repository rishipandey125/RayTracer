#ifndef MATERIAL_H
#define MATERIAL_H
#include "ray.h"
#include "vec.h"
#include "hit.h"
#include "random.cpp"
#include <cmath>

vec reflect(vec &v, vec &n) {
  float product = v.dot(n)*2.0;
  vec reflect = v - (n*product);
  return reflect;
}

vec refract(vec &v, vec &n ,float &cos_theta, float ni_over_nt) {
  vec r_out_perp = (v + (n*cos_theta))*ni_over_nt;
  float length = r_out_perp.length();
  vec r_out_parallel = n * -1.0 * sqrt(fabs(1.0-(length*length)));
  return r_out_perp + r_out_parallel;
}

float schlick(float cosine, float r_i) {
  float r0 = (1-r_i) / (1+r_i);
  r0 = r0*r0;
  return r0 + ((1-r0)*pow((1-cosine),5));
}

class material {
  public:
    color base_color;
    material() {}
    //virtual keyword: means it was declared in the base class and can be redefined in child classes (override)
    virtual bool scatter(hit &record) {
      return false;
    }
};

class diffuse: public material {
  public:
    diffuse(color b_color) {
      base_color = b_color;
    }
    virtual bool scatter(hit &record) {
      point h_point = record.hit_point;
      point target = h_point + record.object_normal + record.random_unit_vec;
      vec scatter = target-h_point;
      record.next_ray = ray(h_point,scatter);
      return true;
    }
};

class metal: public material {
  public:
    metal(color b_color, float f) {
      base_color = b_color;
      fuzz = f;
    }
    virtual bool scatter(hit &record) {
      vec r = reflect(record.casted_ray_direction, record.object_normal);
      vec scatter = r + (record.random_unit_vec*fuzz);
      record.next_ray = ray(record.hit_point,scatter);
      if (record.next_ray.direction.dot(record.object_normal) > 0) {
        return true;
      }
      return false;
    }
    float fuzz;
};

class dielectric: public material {
  public:
    dielectric(float r_i) {
      base_color = color(1,1,1);
      refractive_index = r_i;
    }
    //the bug appears in the middle of the sphere
    virtual bool scatter(hit &record) {
      vec dir = record.casted_ray_direction;
      vec n = record.object_normal;
      float ni_over_nt;
      dir.unit();
      if (dir.dot(n) > 0) {
        n = n * -1.0;
        ni_over_nt = refractive_index;
      } else {
        ni_over_nt = 1.0/refractive_index;
      }
      float cosine = n.dot(dir*-1.0);
      float sin =  sqrt(1.0-(cosine*cosine));
      if (ni_over_nt * sin > 1.0) {
        vec reflect_vec = reflect(dir,n);
        record.next_ray = ray(record.hit_point,reflect_vec);
        return true;
      }
      //perfect refraction works. (mixing schlick doesnt!)
      vec scatter;
      //the middle band is caused by the reflection
      if (random_float() < schlick(cosine,refractive_index)) {
        scatter = reflect(dir,n);
      } else {
        scatter = refract(dir,n,cosine,ni_over_nt);
      }
      record.next_ray = ray(record.hit_point,scatter);
      return true;
     }
    float refractive_index;
};
#endif
