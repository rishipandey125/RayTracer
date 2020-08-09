#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "vec.cpp"
#include "ray.cpp"
#include "sphere.cpp"
#include "camera.cpp"


//ground is just another sphere (just super large) this actually makes sense
color shade(ray &casted_ray, std::vector <sphere> &objects) {
  color pixel(1,1,1);
  // float closest = float(RAND_MAX); //closest t (whatever is closest to camera is what you render)
  for (int i = 0; i < objects.size(); i++) {
    if (objects[i].hit_sphere(casted_ray) > 0.0) {
      pixel = color(1,0,0);
      //if this hit is closer than the previous, update the color
    }
  }
  return pixel;
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

//shouldnt you only antialias on tangents?
//shoot a ray, loop over objects in the scene and if no hit, render bg (include t_nearest)
int main() {
  camera cam;
  //fix the mirrored world sphere issue
  sphere world_sphere(point(0,-50.5,-1),50);
  // sphere first_sphere(point(0.0,0.0,-1),0.5);
  std::vector <sphere> spheres = {world_sphere};
  int image_width = 1000;
  int image_height = (int)(image_width/cam.aspect_ratio);
  int samples = 1;
  //Render Details
  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int j = image_height-1; j >= 0; j--) {
      for (int i = 0; i < image_width; i++) {
          color pixel;
          for (int s = 0; s < samples; s++) {
            float u = (float(i) + random_float())/image_width;
            float v = (float(j) + random_float())/image_height;
            ray cast_ray = cam.get_ray(u,v);
            pixel = pixel + shade(cast_ray,spheres);
          }
        output_color(pixel,samples);
      }
  }
  return 0;
}
