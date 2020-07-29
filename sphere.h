#ifndef SPHERE_H
#define SPHERE_H
#include "vec.h"
class sphere {
  public:
    sphere();
    point center;
    float radius;
    vec get_normal_vector();
};
#endif
