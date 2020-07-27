#include "vec.h"
#include <cmath>
using std::sqrt;

vec::vec() {
  x = 0.0f; y = 0.0f; z = 0.0f;
}

vec::vec(float i, float j, float k) {
  x = i; y = j; z = k;
}

float length() {
  return math.sqrt((x*x)+(y*y)+(z*z));
}

void unit() {
  float length = this.length();
  x = x/length;
  y = y/length;
  z = z/length;
}
float dot(const vec &vector) {
  return (x*vector.x) + (y*vector.y) + (z*vector.z);
}

vec operator+(const vec &vector) {
  return vec(x + vector.x, y + vector.y, z + vector.z);
}

vec operator-(const vec &vector) {
  return vec(x - vector.x, y - vector.y, z - vector.z);
}
vec operator*(const vec &vector) {
  return vec(x * vector.x, y * vector.y, z * vector.z);
}

void print() {
  cout << x << " " << y << " " << z << endl;
}
