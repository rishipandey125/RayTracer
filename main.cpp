#include <iostream>
#include <cstdlib>
#include "vec.cpp"
#include "ray.cpp"
#include "sphere.cpp"
#include "camera.cpp"

color shade(bool hit) {
  if (hit) {
    return color(1,0,0);
  }
  return color(1,1,1);
}

float random_float() {
  return (float) rand()/RAND_MAX;
}
void output_color(color &pixel, int samples) {
  float ratio = 1.0/float(samples);
  color output_pixel = pixel*ratio;
  output_pixel.clamp();
  int r = static_cast<int>(255 * output_pixel.x);
  int g = static_cast<int>(255 * output_pixel.y);
  int b = static_cast<int>(255 * output_pixel.z);
  std::cout << r << ' ' << g << ' ' << b << '\n';
}

bool hit_sphere(ray &casted_ray,const sphere &object) {
  vec ac = casted_ray.origin - object.center;
  float a = casted_ray.direction.dot(casted_ray.direction);
  float b = 2 * casted_ray.direction.dot(ac);
  float c = ac.dot(ac) - (object.radius*object.radius);
  float discriminant = (b*b) - (4*a*c);
  if (discriminant > 0) {
    // (-b-sqrt(disc))/2a = t (the smallest value t can be (from there you can calc the point))
    //point impact = casted_ray.origin + (t * casted_ray.direction)
    return true;
  }
  return false;
}
//shouldnt you only antialias on tangents?
//shoot a ray, loop over objects in the scene and if no hit, render bg (include t_nearest)
int main() {
  camera cam;
  sphere first_sphere(point(0,0,-1),0.5);
  int image_width = 400;
  int image_height = (int)(image_width/cam.aspect_ratio);
  int samples = 1000;
  //Render Details
  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
  for (int j = image_height-1; j >= 0; j--) {
      for (int i = 0; i < image_width; i++) {
          color pixel;
          for (int s = 0; s < samples; s++) {
            float u = (float(i) + random_float())/image_width;
            float v = (float(j) + random_float())/image_height;
            ray cast_ray = cam.get_ray(u,v);
            if (hit_sphere(cast_ray,first_sphere)) {
              pixel = pixel + shade(true);
            } else {
              pixel = pixel + shade(false);
            }
          }
        output_color(pixel,samples);
      }
  }
  return 0;
}
