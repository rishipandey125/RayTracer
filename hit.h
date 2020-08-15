#ifndef HIT_H
#define HIT_H
#include "vec.h"
class sphere;
// Structure for When a Ray Hits an Object
struct hit {
  bool success;
  point hit_point;
  sphere *object;
  vec random_unit_vec;
};
#endif
