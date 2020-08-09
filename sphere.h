#ifndef SPHERE_H
#define SPHERE_H
#include "vec.h"
class sphere {
  public:
    sphere();
    sphere(point sphere_center,float sphere_rad,color pixel);
    vec get_normal_vector(point point_on_sphere);
    float hit_sphere(ray &casted_ray);
    point center;
    float radius;
    color sphere_color;
    // color sphere_color;
};
#endif
