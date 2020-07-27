#ifndef VEC3_H
#define VEC3_H

class vec3 {
  public:
    vec3();
    vec3(float i, float j, float k);
    float length();
    void unit();
    float dot(const vec3 &vector);
    vec3 operator+(const vec3 &vector);
    vec3 operator-(const vec3 &vector);
    vec3 operator*(const vec3 &vector);
    void print();
  private:
    float x;
    float y;
    float z;
};

using point = vec3; //defines a 3d point
using color = vec3; //defines an (r,g,b) color
#endif
