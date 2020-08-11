#ifndef VEC_H
#define VEC_H
//Vector Class Header
class vec {
  public:
    vec();
    vec(float i, float j, float k);
    float length();
    void unit();
    float dot(const vec &vector);
    vec operator+(const vec &vector);
    vec operator-(const vec &vector);
    void operator=(const vec &vector);
    vec operator*(const vec &vector);
    vec operator*(const float &scalar);
    void clamp();
    void print();
    float x,y,z;

};

using point = vec; //defines a 3d point
using color = vec; //defines an (r,g,b) color
#endif
