#include "vec3.h"
// #include <cmath>
using std::sqrt;

vec3::vec3() {
  x = 0.0f; y = 0.0f; z = 0.0f;
}

vec3::vec3(float i, float j, float k) {
  x = i; y = j; z = k;
}

float length() {
  return math.sqrtf((x*x)+(y*y)+(z*z));
}

void unit() {
  float length = this.length();
  x = x/length;
  y = y/length;
  z = z/length;
}
float dot(const vec3 &vector) {
  return (x*vector.x) + (y*vector.y) + (z*vector.z);
}

vec3 operator+(const vec3 &vector) {
  return vec3(x + vector.x, y + vector.y, z + vector.z);
}

vec3 operator-(const vec3 &vector) {
  return vec3(x - vector.x, y - vector.y, z - vector.z);
}
vec3 operator*(const vec3 &vector) {
  return vec3(x * vector.x, y * vector.y, z * vector.z);
}

void print() {
  cout << x << " " << y << " " << z << endl;
}
