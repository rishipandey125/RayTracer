#include "camera.h"
#include <cmath>
//Camera Class

//Default Constructor
camera::camera(point c_origin, float camera_aspect_ratio, float vfov) {
  this->origin = c_origin;
  this->aspect_ratio = camera_aspect_ratio;
  float theta = vfov*(M_PI/180.0);
  float h = tan(theta/2.0);
  // vec lookat(0,0,-1);
  // vec vup(0,1,0);
  // vec w = c_origin - lookat;
  // w.unit();
  // vec u = vup.cross(w);
  // u.unit()
  // vec v = w.cross(u);
  this->viewport_height = 2.0 * h;
  this->viewport_width = this->viewport_height*this->aspect_ratio;
  this->horizontal = vec(viewport_width, 0, 0);
  this->vertical = vec(0,viewport_height,0);
  this->focal_length = 1.0;
  float scale = 2.0;
  this->lower_left_corner = c_origin - this->horizontal/scale - this->vertical/scale - vec(0,0,this->focal_length);
}

//Specific Constructor
camera::camera(point camera_origin, float camera_aspect_ratio,
      float camera_viewport_height, float camera_focal_length) {
  this->origin = camera_origin;
  this->aspect_ratio = camera_aspect_ratio;
  this->viewport_height = camera_viewport_height;
  this->viewport_width = this->viewport_height*this->aspect_ratio;
  this->focal_length = camera_focal_length;
}

//Generate Ray Based Off of UV Frame Location
//we need to decide a system for where the camera can look
//to move the camera we also need to move the viewport
ray camera::get_ray(float &u, float &v) {
  return ray(this->origin, this->lower_left_corner + (this->horizontal*u) + (this->vertical*v) - this->origin);
  // float viewport_x = (u*this->viewport_width)-(this->viewport_width/2);
  // float viewport_y = -1.0*((this->viewport_height/2)-(v*this->viewport_height));
  // float viewport_z = -1.0*this->focal_length;
  // point viewport_point(viewport_x,viewport_y,viewport_z);
  // vec direction = viewport_point-this->origin;
  // ray cast_ray(this->origin,direction);
  // return cast_ray;
}
