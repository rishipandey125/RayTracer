#ifndef VEC_H
#define VEC_H

class vec {
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
  private:
    float x;
    float y;
    float z;
};

using point = vec; //defines a 3d point
using color = vec; //defines an (r,g,b) color
#endif
