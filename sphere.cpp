#include "sphere.h"
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
  float a = casted_ray.direction.length();
  // std::cerr << a << std::endl;
  float b = 2 * casted_ray.direction.dot(ac);
  float c = ac.dot(ac) - (this->radius*this->radius);
  float discriminant = (b*b) - (4*a*c);
  if (discriminant >= 0.0) {
    float t = ((-b-sqrt(discriminant))/(2*a));
    if (t < 1e-15) {
      t = ((-b+sqrt(discriminant))/(2*a));
      if (this->sphere_material->base_color == color(1,1,1))
        std::cout << t << std::endl;
      // point second_point = casted_ray.get_point_at(t);
      // float length = (second_point - this->center).length();
      // if (length == this->radius) {
      //   return t;
      // } else {
      //   return 0;
      // }
    //   // if (this->sphere_material->base_color == color(1,1,1)) {
    //   //   t = ((-b+sqrt(discriminant))/(2*a));
    //   //   std::cout << "Ray Origin: " << std::endl;
    //   //   casted_ray.origin.print();
    //   //   std::cout << "Ray Direction: " << std::endl;
    //   //   casted_ray.direction.print();
    //   //   std::cout << "First t = 0 hit point:" << std::endl;
    //   //   casted_ray.get_point_at(0).print();
    //   //   point second_point = casted_ray.get_point_at(t);
    //   //   std::cout << "Second t: " << t << std::endl;
    //   //   float length = (second_point - this->center).length();
    //   //   std::cout << "Second Hit Point:" << std::endl;
    //   //   second_point.print();
    //   //   std::cout << "Second Point dist from center: " << length << std::endl;
    //   //   std::cout << "Radius: " << this->radius << std::endl;
    //   //   std::cout << "   " << std::endl;
    //   // }
    }
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
