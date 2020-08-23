#include "vec.h"
#include <cmath>
using std::sqrt;
//Vector Class

//Default Constructor
vec::vec() {
  this->x = 0.0f; this->y = 0.0f; this->z = 0.0f;
}

// Specific Constructor
vec::vec(float i, float j, float k) {
  this->x = i;
  this->y = j;
  this->z = k;
}

//Get Length or Magnitude of a Vector
float vec::length() {
  return sqrt((this->x*this->x)+(this->y*this->y)+(this->z*this->z));
}

//Set Vector to be Unit Vector
void vec::unit() {
  float length = this->length();
  this->x = this->x/length;
  this->y = this->y/length;
  this->z = this->z/length;
}

//Dot Product
float vec::dot(const vec &vector) {
  return (this->x*vector.x) + (this->y*vector.y) + (this->z*vector.z);
}

vec vec::cross(const vec &vector) {
  float x = (this->y*vector.z)-(this->z*vector.y);
  float y = -1.0 * ((this->x*vector.z)-(this->z*vector.x));
  float z = (this->x*vector.y)-(this->y*vector.x);
  return vec(x,y,z);
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

//Clamping Color on RGB Scale
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

//Square Root of Each term in a Vec
void vec::root() {
  this->x = sqrt(this->x);
  this->y = sqrt(this->y);
  this->z = sqrt(this->z);
}

//Ease of Access Print Vector Function
void vec::print() {
  std::cout << "<" <<  this->x << "," << this->y << "," << this->z << ">" << std::endl;
}
