#include "sphere.h"

sphere::sphere() {}

sphere::sphere(point sphere_center, float sphere_rad) {
  this->center = sphere_center;
  this->radius = sphere_rad;
}

//problem with ground sphere must be here
//FOUND THE PROBLEM: IT CALCULATES VALUES FOR NEGATIVE T ON THE RAY
//SO IF THE RAY SHOOTS UP, IT WILL FIND A VALUE OF NEGATIVE T WHERE IT HITS
//BELOW. LIKE IF THE RAY IS UP AND RIGHT, IT WILL BACKTRACK BACK AND LEFT AND HIT
//SOMETHING BEHIND THE CAMERA AND RENDER THAT OUT FIX THIS BY CALCULATING T
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

vec sphere::get_normal_vector(point point_on_sphere) {
  return point_on_sphere - this->center;
}
