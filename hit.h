#ifndef HIT_H
#define HIT_H
#include "vec.h"
//forward decleration because sphere references material, and material references hit, so hit cant ref sphere
class sphere;

// Structure for When a Ray Hits an Object
struct hit {
  bool success = false;
  point hit_point;
  sphere *object;
  vec casted_ray_direction;
  vec object_normal;
  vec random_unit_vec;
};
#endif
