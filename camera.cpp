#include "camera.h"
#include <cmath>
#include "random.cpp"
/*
Camera Class
Features: Moving Camera, Apeture, and FOV Control
*/

//Updating Frame Settings Every Frame
void camera::update_frame_settings() {
  float theta = this->vertical_fov*(M_PI/180.0);
  float h = tan(theta/2.0);
  vec vup(0,1,0);
  //apeture disk
  this->w = this->origin - this->look_at; this->w.unit();
  this->u = vup.cross(this->w); this->u.unit();
  this->v = this->w.cross(this->u);
  float focus_distance = vec(this->origin-this->look_at).length();
  float viewport_height = 2.0 * h;
  float viewport_width = viewport_height*this->aspect_ratio;
  this->horizontal = this->u*focus_distance*viewport_width;
  this->vertical = this->v*focus_distance*viewport_height;
  this->focal_length = 1.0;
  float scale = 2.0;
  this->lower_left_corner = this->origin - this->horizontal/scale - this->vertical/scale - (this->w*focus_distance);
  this->lens_radius = this->apeture/2.0;
}

//Camera Constructor
camera::camera(point s_point, point e_point, point l_at, float camera_aspect_ratio,
              float s_fov, float e_fov,
              float s_apeture, float e_apeture,
              int total_frames) {
  this->origin = s_point;
  vec direction = e_point-s_point;
  this->camera_path = ray(s_point,direction);
  this->look_at = l_at;
  this->aspect_ratio = camera_aspect_ratio;
  this->start_apeture = s_apeture;
  this->end_apeture = e_apeture;
  this->start_fov = s_fov;
  this->end_fov = e_fov;
  this->num_frames = total_frames;
  this->frame_count = 0;
  this->capture_complete = false;
}

//Generate Ray Based Off of UV Frame Location
ray camera::get_ray(float &x_pos, float &y_pos) {
  vec lens = random_in_unit_disk() * this->lens_radius;
  vec offset = (this->u*lens.x) + (this->v*lens.y);
  return ray(this->origin + offset,
            this->lower_left_corner + (this->horizontal*x_pos) + (this->vertical*y_pos) - this->origin - offset);
}

//Updates all the parameters and sets the lower_left_corner viewport iteration pattern for each capture
void camera::next_capture() {
  float ratio = 0.33;
  float r = float(frame_count)/float(num_frames);
  float apt = 0;
  //for controlling base shot
  if (r < ratio) {
    apt = r / ratio;
    r = 0;
  } else {
    apt = 1;
    r = (r-ratio)/(1.0-ratio);
  }
   //update origin
  this->origin = this->camera_path.get_point_at(r);

   //update apeture
  // this->apeture = this->start_apeture - ((this->start_apeture-this->end_apeture)*r);
  this->apeture = this->start_apeture - ((this->start_apeture-this->end_apeture)*apt);

   //update fov
  this->vertical_fov = this->start_fov - ((this->start_fov-this->end_fov)*r);

   //vertigo shot code
   // float theta = this->vertical_fov*(M_PI/180.0);
   // float w = 1.154700538;
   // float val = w/(2*tan(theta/2.0));
   // this->origin = point(0,0,val+(this->look_at.z));

   //update frame_settings
  update_frame_settings();
   //update frame_count
  this->frame_count += 1;
  if (this->frame_count == this->num_frames) {
    this->capture_complete = true;
  }
}
