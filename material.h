#ifndef MATERIAL_H
#define MATERIAL_H
#include "ray.h"
#include "vec.h"
#include "hit.h"
//circular dependency has everything to do with how we declare hit here
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
    metal(color b_color) {
      base_color = b_color;
    }
    virtual bool scatter(hit &record) {
      vec v = record.casted_ray_direction;
      vec n = record.object_normal;
      float product  = v.dot(n)*2.0;
      vec reflect = v - (n*product);
      record.next_ray = ray(record.hit_point,reflect-record.hit_point);
      if (record.next_ray.direction.dot(n) > 0) {
        return true;
      }
      return false;
    }
};
#endif
