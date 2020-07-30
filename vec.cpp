#include "vec.h"
#include <cmath>
using std::sqrt;

vec::vec() {
  this->x = 0.0f; this->y = 0.0f; this->z = 0.0f;
}

vec::vec(float i, float j, float k) {
  this->x = i;
  this->y = j;
  this->z = k;
}

float vec::length() {
  return sqrt((this->x*this->x)+(this->y*this->y)+(this->z*this->z));
}

void vec::unit() {
  float length = this->length();
  this->x = this->x/length;
  this->y = this->y/length;
  this->z = this->z/length;
}
float vec::dot(const vec &vector) {
  return (this->x*vector.x) + (this->y*vector.y) + (this->z*vector.z);
}

vec vec::operator+(const vec &vector) {
  return vec(this->x + vector.x, this->y + vector.y, this->z + vector.z);
}

void vec::operator=(const vec &vector) {
  this->x = vector.x;
  this->y = vector.y;
  this->z = vector.z;
}

vec vec::operator-(const vec &vector) {
  return vec(this->x - vector.x, this->y - vector.y, this->z - vector.z);
}
vec vec::operator*(const vec &vector) {
  return vec(this->x * vector.x, this->y * vector.y, this->z * vector.z);
}

vec vec::operator*(const float &scalar) {
  return vec(this->x * scalar, this->y * scalar, this->z * scalar);
}

void vec::clamp() {
  if (this->x > 1) {
    this->x = 1;
  } else if (this->x < 0) {
    this->x = 0;
  }
  if (this->y > 1) {
    this->y = 1;
  } else if (this->y < 0) {
    this->y = 0;
  }
  if (this->z > 1) {
    this->z = 1;
  } else if (this->z < 0) {
    this->z = 0;
  }
}

void vec::print() {
  std::cout << "<" <<  this->x << "," << this->y << "," << this->z << ">" << std::endl;
}
