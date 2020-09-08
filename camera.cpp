#include "camera.h"
#include <cmath>
#include "random.cpp"
/*
Animated Camera Features: Moveable Camera (Changing c_origin around the look_at), static look_at, focusing feature (change aperture)
zoom feature (changing vfov)
capture length
start point - end point
start fov - end fov
start apeture - end apeture
capture_complete bool parameter
*/
//Camera Class
//Camera Constructor
camera::camera(point c_origin, point look_at, float camera_aspect_ratio, float vfov, float aperture, int c_length) {
  this->origin = c_origin;
  this->aspect_ratio = camera_aspect_ratio;
  this->capture_length = c_length;
  //fov
  float theta = vfov*(M_PI/180.0);
  float h = tan(theta/2.0);
  vec vup(0,1,0);
  //apeture disk
  this->w = c_origin - look_at; this->w.unit();
  this->u = vup.cross(this->w); this->u.unit();
  this->v = this->w.cross(this->u);
  float focus_distance = vec(c_origin-look_at).length();
  float viewport_height = 2.0 * h;
  float viewport_width = viewport_height*this->aspect_ratio;
  this->horizontal = this->u*focus_distance*viewport_width;
  this->vertical = this->v*focus_distance*viewport_height;
  this->focal_length = 1.0;
  float scale = 2.0;
  this->lower_left_corner = c_origin - this->horizontal/scale - this->vertical/scale - (this->w*focus_distance);
  this->lens_radius = aperture/2.0;
}
//this is a comment i am adding
//Generate Ray Based Off of UV Frame Location
ray camera::get_ray(float &x_pos, float &y_pos) {
  vec lens = random_in_unit_disk() * this->lens_radius;
  vec offset = (this->u*lens.x) + (this->v*lens.y);
  return ray(this->origin + offset,
            this->lower_left_corner + (this->horizontal*x_pos) + (this->vertical*y_pos) - this->origin - offset);
}

//updates all the parameters and sets the lower_left_corner viewport iteration pattern
void camera::next_capture() {
   float r = float(frame_count)/float(num_frames);
   //update origin
   //update apeture
   this->apeture = this->start_apeture - ((this->start_apeture-this->end_aperture)*r;
   //update fov
   this->v_fov = this->start_fov - ((this->start_fov-this->end_fov)*r;
   //update frame_settings
   update_frame_settings();
   //update frame_count
   this->frame_count += 1;
   if (this->frame_count == this->num_frames) {
     this->capture_complete = true;
   }
}

void update_frame_settings() {

}
