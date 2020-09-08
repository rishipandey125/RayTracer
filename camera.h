#ifndef CAMERA_H
#define CAMERA_H
#include "vec.h"
#include "ray.h"

//Camera Class Header
class camera {
  public:
    camera(point c_origin, point look_at, float camera_aspect_ratio, float vfov, float aperture);
    ray get_ray(float &x_pos, float &y_pos);
    void next_capture();
    point origin;
    float aspect_ratio;
    float focal_length;
    float vertical_fov;
    float lens_radius;
    int frame_count;
    int num_frames;
    bool capture_complete;
    vec lower_left_corner;
    vec horizontal, vertical;
    vec u, v, w;

};

#endif
