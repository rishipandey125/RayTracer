#ifndef HIT_H
#define HIT_H
#include "sphere.h"
#include "vec.h"

// typedef struct hit hit;

// Structure for When a Ray Hits an Object
struct hit {
  bool success;
  point hit_point;
  sphere object;
  // hit() {
  //   success = false;
  // }
  // hit(bool s, point p, sphere sp) {
  //   success = s;
  //   hit_point = p;
  //   object = sp;
  // }
};
#endif
