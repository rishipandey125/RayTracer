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
    // virtual ray scatter(hit record) {};
    virtual ray scatter(hit record) {
      point h_point = record.hit_point;
        point target = h_point + record.sphere_normal + record.random_unit_vec;
      return ray(h_point,target-h_point);
    }
};
//
// class diffuse: public material {
//   public:
//     diffuse(color b_color) {
//       base_color = b_color;
//     }
//     // color base_color;
//     virtual ray scatter(hit &record) override{
//       point h_point = record.hit_point;
//       point target = h_point + record.object.get_normal_vector(h_point) + record.random_unit_vec;
//       return ray(h_point,target-h_point);
//     }
// };
#endif
