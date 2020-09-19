#include "ray.h"
//Ray Class

//Default Constructor
ray::ray() {}

//Specific Constructor (Origin and Direction)
ray::ray(const point &ray_origin, const vec &ray_direction) {
  this->origin = ray_origin;
  this->direction = ray_direction;
}

//Get Point at Parametric Location (t) on Ray
point ray::get_point_at(float t) {
  return this->origin + (this->direction * t);
}
