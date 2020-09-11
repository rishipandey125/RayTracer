#ifndef CAMERA_H
#define CAMERA_H
#include "vec.h"
#include "ray.h"

//Camera Class Header
class camera {
  public:
    camera(point s_point, point e_point, point l_at, float camera_aspect_ratio,
                  float s_fov, float e_fov,
                  float s_apeture, float e_apeture,
                  int total_frames);
    ray get_ray(float &x_pos, float &y_pos);
    void next_capture();
    void update_frame_settings();
    point origin;
    point look_at;
    ray camera_path;
    float path;
    float aspect_ratio;
    float focal_length;
    float vertical_fov;
    float apeture;
    float start_apeture;
    float end_apeture;
    float start_fov;
    float end_fov;
    float lens_radius;
    int frame_count;
    int num_frames;
    bool capture_complete;
    vec lower_left_corner;
    vec horizontal, vertical;
    vec u, v, w;

};

#endif
