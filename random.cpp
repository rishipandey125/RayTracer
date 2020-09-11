#pragma once
#include <cstdlib>
#include <cmath>
#include "vec.h"
//Random Generation File
//Generates Random Float between 0 and 1
float random_float() {
  return ((float) rand()/RAND_MAX);
}

//Generates Random Float between min and max
float random_float(float min, float max) {
  return min + ((max-min)*random_float());
}

//Creates a random unit vector from the unit sphere
vec random_unit_vector() {
  float a = random_float(0.0,2.0*M_PI);
  float z = random_float(-1.0,1.0);
  float r = sqrt(1-(z*z));
  return vec(r*cos(a),r*sin(a),z);
}

vec random_in_unit_disk() {
  while (true) {
    vec p = vec(random_float(-1,1),random_float(-1,1),0);
    if (p.length() >= 1) {
      continue;
    }
    return p;
  }
}
