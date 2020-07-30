#ifndef CAMERA_H
#define CAMERA_H
#include "vec.h"

class camera {
  public:
    camera();
    camera(point camera_origin, float camera_aspect_ratio,
          float camera_viewport_height, float camera_focal_length);
    point origin;
    float aspect_ratio;
    float viewport_height;
    float viewport_width;
    float focal_length;

};

#endif
