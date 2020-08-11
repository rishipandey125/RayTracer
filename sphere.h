#ifndef SPHERE_H
#define SPHERE_H
#include "vec.h"
//Sphere Class Header
class sphere {
  public:
    sphere();
    sphere(point sphere_center,float sphere_rad,color s_color);
    vec get_normal_vector(point point_on_sphere);
    float hit_sphere(ray &casted_ray);
    point center;
    float radius;
    color sphere_color;
};
#endif
