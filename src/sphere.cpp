#include "sphere.h"
#include <cmath>
//Sphere Object Class

//Default Constructor
sphere::sphere() {}

//Specific Constructor: Center, Radius, and Material
sphere::sphere(point sphere_center, float sphere_rad, material *mat) {
  this->center = sphere_center;
  this->radius = sphere_rad;
  this->sphere_material = mat;
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
    // both negative = no hit
    // both positive = hit from outside take the first one
    // one negative and one positive take the positve one (comes from inside)
    float t_first = ((-b-sqrt(discriminant))/(2*a));
    float t_second = ((-b+sqrt(discriminant))/(2*a));
    if (t_first > 0.001) {
      return t_first;
    } else if (t_second > 0.001) {
      return t_second;
    }
  }
  return -1.0;
}

//Get Normal Vector of Sphere at a Specific Point
vec sphere::get_normal_vector(point point_on_sphere) {
  return point_on_sphere - this->center;
}

//Print Function for Debugging
void sphere::print() {
  std::cout << "Sphere at Center:" << std::endl;
  this->center.print();
  std::cout << "With Radius: " << this->radius << std::endl;
}
