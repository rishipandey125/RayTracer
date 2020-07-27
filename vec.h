#ifndef VEC_H
#define VEC_H

class vec {
  float x,y,z;
  public:
    vec();
    vec(float i, float j, float k);
    float length();
    void unit();
    float dot(const vec &vector);
    vec operator+(const vec &vector);
    vec operator-(const vec &vector);
    vec operator*(const vec &vector);
    void print();

};

using point = vec; //defines a 3d point
using color = vec; //defines an (r,g,b) color
#endif
