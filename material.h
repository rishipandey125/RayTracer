#ifndef MATERIAL_H
#define MATERIAL_H
#include "ray.h"
#include "vec.h"
#include "hit.h"

vec reflect(vec &v, vec &n) {
  //n has to be a unit vector
  float product = v.dot(n)*2.0;
  vec reflect = v - (n*product);
  return reflect;
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
      record.next_ray = ray(h_point,target-h_point);
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
      vec n = record.object_normal;
      // n.unit();
      vec r = reflect(record.casted_ray_direction, n);
      vec scatter = r + (record.random_unit_vec*fuzz);
      record.next_ray = ray(record.hit_point,scatter-record.hit_point);
      if (record.next_ray.direction.dot(n) > 0) {
        return true;
      }
      return false;
    }
    float fuzz;
};

// class dialectric: public material {
//   public:
//     dialectric(float r_i) {
//       base_color = color(1.0,1.0,1.0);
//       refractive_index = r_i;
//     }
//     virtual bool scatter(hit &record) {
//       //v is the normal vector starting at hitpoint to center
//
//       //internal normal vector?
//     }
//     float refractive_index;
// };
#endif
