#include "camera.h"

camera::camera() {
  this->origin = point(0,0,0);
  this->aspect_ratio = 16.0/9.0;
  this->viewport_height = 2.0;
  this->viewport_width = this->viewport_height*this->aspect_ratio;
  this->focal_length = 1.0;
}

camera::camera(point camera_origin, float camera_aspect_ratio,
      float camera_viewport_height, float camera_focal_length) {
  this->origin = camera_origin;
  this->aspect_ratio = camera_aspect_ratio;
  this->viewport_height = camera_viewport_height;
  this->viewport_width = this->viewport_height*this->aspect_ratio;
  this->focal_length = camera_focal_length;
}

ray camera::get_ray(float &u, float &v) {
  float viewport_x = (u*this->viewport_width)-(this->viewport_width/2);
  //v = 0.1 with viewport_height = 2: should be -0.8
  //error exists in viewport_y -1 * (1-(.1*2)) =
  float viewport_y = -1.0*((this->viewport_height/2)-(v*this->viewport_height));
  // std::cout << viewport_y << std::endl;
  float viewport_z = -1.0*this->focal_length;
  point viewport_point(viewport_x,viewport_y,viewport_z);
  vec direction = viewport_point-this->origin;
  ray cast_ray(this->origin,direction);
  return cast_ray;
}
