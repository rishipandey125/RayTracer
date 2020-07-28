#include "ray.h"
ray::ray() {}

ray::ray(const point &rayOrigin, const vec &rayDirection) {
  this->origin = rayOrigin;
  this->direction = rayDirection;
}

float ray::getPointAt(float t) {
  return this->origin + (t * this->direction);
}
