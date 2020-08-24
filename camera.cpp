#include "camera.h"
#include <cmath>
#include "random.cpp"
/*
Here is how the disk DOF works: for every point in the disk - treat that like a pinhole camera.
That means you have a ton of pinhole cameras in a disk. Each pinhole camera can shoot rays and create an image.
If those images are averaged together then everything - but the thing in the focus point will be out of focus.
This is because we are looking at objects from different views a bunch of times and then averaging those views.
This is what causes the blurriness. There is only one thing in focus because all the pinhole cameras are told to look at
one thing. This Allows us to create a depth of field. The larger the apeture (lower the f-stop) the more pinhole cameras
you have. This means that there will be a higher depth of field because things not in focus will be blurrier. 
*/
//Camera Class
//Camera Constructor
camera::camera(point c_origin, point look_at, float camera_aspect_ratio, float vfov, float aperture) {
  this->origin = c_origin;
  this->aspect_ratio = camera_aspect_ratio;
  float theta = vfov*(M_PI/180.0);
  float h = tan(theta/2.0);
  vec vup(0,1,0);
  this->w = c_origin - look_at; this->w.unit();
  this->u = vup.cross(this->w); this->u.unit();
  this->v = this->w.cross(this->u);
  float focus_distance = this->w.length();
  float viewport_height = 2.0 * h;
  float viewport_width = viewport_height*this->aspect_ratio;
  this->horizontal = this->u*focus_distance*viewport_width;
  this->vertical = this->v*focus_distance*viewport_height;
  this->focal_length = 1.0;
  float scale = 2.0;
  this->lower_left_corner = c_origin - this->horizontal/scale - this->vertical/scale - (this->w*focus_distance);
  this->lens_radius = aperture/2.0;
}

//Generate Ray Based Off of UV Frame Location
ray camera::get_ray(float &x_pos, float &y_pos) {
  vec lens = random_in_unit_disk() * this->lens_radius;
  vec offset = (this->u*lens.x) + (this->v*lens.y);
  return ray(this->origin + offset,
            this->lower_left_corner + (this->horizontal*x_pos) + (this->vertical*y_pos) - this->origin - offset);
}
