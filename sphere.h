#ifndef SPHERE_H
#define SPHERE_H
#include "vec.h"
class sphere {
  public:
    sphere();
    sphere(point sphere_center,float sphere_rad);
    vec get_normal_vector(point point_on_sphere);
    bool hit_sphere(ray &casted_ray);
    point center;
    float radius;
};
#endif
