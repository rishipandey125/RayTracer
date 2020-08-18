#ifndef SPHERE_H
#define SPHERE_H
#include "vec.h"
#include "material.h"

//Sphere Class Header
class sphere {
  public:
    sphere();
    sphere(point sphere_center,float sphere_rad,material *mat);
    vec get_normal_vector(point point_on_sphere);
    float hit_sphere(ray &casted_ray);
    void print();
    point center;
    float radius;
    material *sphere_material;
};
#endif
