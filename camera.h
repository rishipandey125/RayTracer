#ifndef CAMERA_H
#define CAMERA_H
#include "vec.h"
#include "ray.h"

//Camera Class Header
class camera {
  public:
    camera(point c_origin, float camera_aspect_ratio, float vfov);
    camera(point camera_origin, float camera_aspect_ratio,
          float camera_viewport_height, float camera_focal_length);
    ray get_ray(float &u, float &v);
    point origin;
    float aspect_ratio;
    float viewport_height;
    float viewport_width;
    float focal_length;
    float vertical_fov;

};

#endif
