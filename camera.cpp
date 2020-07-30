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
