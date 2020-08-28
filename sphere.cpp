#include "sphere.h"
#include <cmath>
//Sphere Object Class

//Default Constructor
sphere::sphere() {}

//Specific Constructor
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
  std::cout << "Length of Casted Ray (A): " << a << std::endl;
  std::cout << "Lenght of Casted Ray (Vec Internal)" << casted_ray.direction.length() << std::endl;
  float b = 2 * casted_ray.direction.dot(ac);
  float c = ac.dot(ac) - (this->radius*this->radius);
  float discriminant = (b*b) - (4*a*c);
  if (discriminant > 0.0) {
    float t = ((-b-sqrt(discriminant))/(2*a));
    return t;
  }
  return -1.0;
}

//Get Normal Vector of Sphere at a Specific Point
vec sphere::get_normal_vector(point point_on_sphere) {
  return point_on_sphere - this->center;
}

void sphere::print() {
  std::cout << "Sphere at Center:" << std::endl;
  this->center.print();
  std::cout << "With Radius: " << this->radius << std::endl;
}
