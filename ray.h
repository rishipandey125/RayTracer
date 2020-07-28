#ifndef RAY_H
#define RAY_H
#include "vec.h"

class ray {
  public:
    ray();
    ray(const point &rayOrigin, const vec &rayDirection);
    point getPointAt(float t);
    point origin;
    vec direction;

};
#endif
