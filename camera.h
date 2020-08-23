#ifndef CAMERA_H
#define CAMERA_H
#include "vec.h"
#include "ray.h"

//Camera Class Header
class camera {
  public:
    camera(point c_origin, float camera_aspect_ratio, float vfov);
    ray get_ray(float &u, float &v);
    point origin;
    float aspect_ratio;
    float viewport_height;
    float viewport_width;
    float focal_length;
    float vertical_fov;
    vec lower_left_corner;
    vec horizontal;
    vec vertical;

};

#endif
