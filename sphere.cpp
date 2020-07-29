#include "sphere.h"

sphere::sphere() {}

sphere::sphere(point sphere_center, float sphere_rad) {
  this->center = sphere_center;
  this->radius = sphere_rad;
}

vec sphere::get_normal_vector(point point_on_sphere) {
  return point_on_sphere - this->center;
}
