#include "ray.h"
ray::ray() {}

ray::ray(const point &rayOrigin, const vec &rayDirection) {
  this->origin = rayOrigin;
  this->direction = rayDirection;
}

point ray::getPointAt(float t) {
  return this->origin + (this->direction * t);
}
