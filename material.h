#ifndef MATERIAL_H
#define MATERIAL_H
#include "ray.h"
#include "vec.h"
#include "hit.h"

vec reflect(vec &v, vec &n) {
  float product = v.dot(n)*2.0;
  vec reflect = v - (n*product);
  return reflect;
}

// vec refract(vec &v, vec&n, float r_q) {
//   v.unit();
//   float dot = v.dot(n);
//   float disc = 1.0 - (r_q*r_q*(1-(dot*dot));
//   if (disc > 0) {
//     refracted = r_q * (v - (n * dot)) - (n*sqrt(disc));
//     return true;
//   }
//   return false;
// }
//
// float schlick(float cosine, float ref_idx) {
//   float r0 = (1-ref_idx) / (1+ref_idx);
//   r0 = r0*r0;
//   return (r0 + (1-r0) * pow(1-cosine,5.0))
// }


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

// class dialectric: public material {
//   public:
//     dialectric(float r_i) {
//       base_color = color(1.0,1.0,1.0);
//       refractive_index = r_i;
//     }
//     virtual bool scatter(hit &record) {
//       //v is the normal vector starting at hitpoint to center
//
//
//       //internal normal vector?
//     }
//     float refractive_index;
// };
#endif
