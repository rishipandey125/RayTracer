#include "camera.h"
#include <cmath>
//Camera Class

//Default Constructor
camera::camera(point c_origin, float camera_aspect_ratio, float vfov) {
  this->origin = c_origin;
  this->aspect_ratio = camera_aspect_ratio;
  float theta = vfov*(M_PI/180.0);
  float h = tan(theta/2.0);
  vec lookat(0,0,-1);
  vec vup(0,1,0);
  vec w = c_origin - lookat; w.unit();
  vec u = vup.cross(w); u.unit();
  vec v = w.cross(u);
  float viewport_height = 2.0 * h;
  float viewport_width = viewport_height*this->aspect_ratio;
  this->horizontal = u*viewport_width;
  this->vertical = v*viewport_height;
  this->focal_length = 1.0;
  float scale = 2.0;
  this->lower_left_corner = c_origin - this->horizontal/scale - this->vertical/scale - w;
}

//Generate Ray Based Off of UV Frame Location
ray camera::get_ray(float &u, float &v) {
  return ray(this->origin, this->lower_left_corner + (this->horizontal*u) + (this->vertical*v) - this->origin);
}
