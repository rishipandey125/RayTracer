#ifndef VEC3_H
#define VEC3_H

class vec3 {
  public:
    vec3();
    vec3(float i, float j, float k);
    float length();
    void unit();
    vec3 operator+(const vec3 &vector);
    vec3 operator-(const vec3 &vector);
    vec3 operator*(const vec3 &vector);

  public:
    float x;
    float y;
    float z;
}
#endif
