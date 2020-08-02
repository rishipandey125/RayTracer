#include "sphere.h"

sphere::sphere() {}

sphere::sphere(point sphere_center, float sphere_rad) {
  this->center = sphere_center;
  this->radius = sphere_rad;
}

bool sphere::hit_sphere(ray &casted_ray) {
  vec ac = casted_ray.origin - this->center;
  float a = casted_ray.direction.dot(casted_ray.direction);
  float b = 2 * casted_ray.direction.dot(ac);
  float c = ac.dot(ac) - (this->radius*this->radius);
  float discriminant = (b*b) - (4*a*c);

  if (discriminant > 0) {
    // float t = ((-b-sqrt(discriminant))/(2*a));
    // (-b-sqrt(disc))/2a = t (the smallest value t can be (from there you can calc the point))
    //point impact = casted_ray.origin + (t * casted_ray.direction)
    //return point of impact and t value
    return true;
  }
  return false;
}

vec sphere::get_normal_vector(point point_on_sphere) {
  return point_on_sphere - this->center;
}
