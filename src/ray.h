#ifndef RAY_H
#define RAY_H
#include "vec.h"
//Ray Class Header
class ray {
  public:
    ray();
    ray(const point &ray_origin, const vec &ray_direction);
    point get_point_at(float t);
    point origin;
    vec direction;

};
#endif
