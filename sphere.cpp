#include "sphere.h"
//Sphere Object Class

//Default Constructor
sphere::sphere() {}

//Specific Constructor
sphere::sphere(point sphere_center, float sphere_rad, color s_color) {
  this->center = sphere_center;
  this->radius = sphere_rad;
  this->sphere_color = s_color;
}

/*
Hit Sphere Function.
Calculates Discriminant - Checks for Roots
Returns the Closest Hit in Parametric Value
*/
float sphere::hit_sphere(ray &casted_ray) {
  vec ac = casted_ray.origin - this->center;
  float a = casted_ray.direction.dot(casted_ray.direction);
  float b = 2 * casted_ray.direction.dot(ac);
  float c = ac.dot(ac) - (this->radius*this->radius);
  float discriminant = (b*b) - (4*a*c);
  if (discriminant > 0.0) {
    float t = ((-b-sqrt(discriminant))/(2*a));
    return t;
    // point impact = casted_ray.origin + (casted_ray.direction*t);
  }
  return -1.0;
}

//Get Normal Vector of Sphere at a Specific Point
vec sphere::get_normal_vector(point point_on_sphere) {
  return point_on_sphere - this->center;
}
