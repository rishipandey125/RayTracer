#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "vec.cpp"
#include "ray.cpp"
#include "sphere.cpp"
#include "camera.cpp"

/*
Diffuse Notes:
Diffuse lighting comes from multiple bounces and collects light from the objects around it.
If you hit an object, create another ray in a random direction,
Random direction: your current point is p
normal vector of the sphere at point p is n
point s is a random point in the unit sphere
your target is
your new ray created has an origin of point p and a direction of target-p
if that hits something you keep diluting the end color (global illumination)

Keep doing this until you stop hitting stuff or you reach the ray depth
We are using global illumination (so there is no local light source the sky is essentially the light source)
*/

struct hit {
  bool success;
  float t;
  sphere object;
  hit() {
    bool = false;
    t = 0.0;
    object = NULL;
  }
  hit(bool s, float val, sphere sp) {
    success = s;
    t = s;
    object = sp;
  }
}

float random_float() {
  return ((float) rand()/RAND_MAX);
}

float random_float(float min, float max) {
  return min + ((max-min)*random_float());
}

vec random_unit_vector() {
  float a = random_float(0.0,2.0*M_PI);
  float z = random_float(-1.0,1.0);
  float r = sqrt(1-(z*z));
  return vec(r*cos(a),r*sin(a),z);
}

color trace(ray &casted_ray, std::vector <sphere> &objects, int depth) {
  //create gradient background
  if (depth <= 0) {
    return color(0,0,0);
  }
  vec unit_direction = casted_ray.direction;
  unit_direction.unit();
  float val = (unit_direction.y+1.0)/2.0;
  color pixel = color(1.0, 1.0, 1.0)*(1-val) + color(0.5, 0.7, 1.0)*val;
  float closest = float(RAND_MAX); //closest t (whatever is closest to camera is what you render)
  //save which object is hit basically by return the sphere, point, and normal vec?
  //create a separate hit func? or hit structure

  //create a hit object (after iterating through all objects we have the nearest hit if there is one)
  for (int i = 0; i < objects.size(); i++) {
    float t = objects[i].hit_sphere(casted_ray);
    if (t > 0.0) {
      if (t < closest) {

        closest = t;
        pixel = color(1,0,0); //this is where we would do a recursive call
      }
    }
  }
  // if () we hit something 
  //if you did hit something, retrace from that point and normal vec
  return pixel;
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

int main() {
  camera cam;
  sphere world_sphere(point(0,-50.5,-1),50);
  sphere first_sphere(point(0.0,0.0,-1),0.5);
  std::vector <sphere> spheres = {world_sphere,first_sphere};
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
            pixel = pixel + trace(cast_ray,spheres,50);
          }
        output_color(pixel,samples);
      }
  }
  return 0;
}
