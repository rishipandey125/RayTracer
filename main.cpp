#include <iostream>
#include "vec.cpp"
#include "ray.cpp"
#include "sphere.cpp"

void output_color(const color &pixel) {
  int r = static_cast<int>(255.999 * pixel.x);
  int g = static_cast<int>(255.999 * pixel.y);
  int b = static_cast<int>(255.999 * pixel.z);
  std::cout << r << ' ' << g << ' ' << b << '\n';
}

bool hit_sphere(const ray &casted_ray, const sphere &object) {
  vec ac = casted_ray.origin - object.center;
  float a = casted_ray.direction.dot(casted_ray.direction);
  float b = 2 * casted_ray.direction.dot(ac);
  float c = ac.dot(ac) - (object.radius*object.radius);
  float discriminant = (b*b) - (4*a*c);
  return (discriminant > 0);
}

int main() {
  //Image Details
  float aspect_ratio = 16.0/9.0;
  point sphere_center(0,0,-1);
  sphere first_sphere(sphere_center,0.5);
  int image_width = 400;
  int image_height = (int)(image_width/aspect_ratio);

  //Camera Details
  point camera_origin(0,0,0);
  float viewport_height = 2.0;
  float viewport_width = viewport_height*aspect_ratio;
  float focal_length = 1.0; // sets viewport at z = -1

  //Render Details
  // set viewport rays to cast through image loop
  // std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
  for (int j = image_height-1; j >= 0; j--) {
      for (int i = 0; i < image_width; i++) {
          float u = i/image_width;
          float v = j/image_height;
          point viewport_point((u*viewport_width)-(viewport_width/2),(v*viewport_height)-(viewport_height/2),-1*focal_length);
          vec direction = viewport_point-camera_origin;
          ray cast_ray(camera_origin,direction);
          if (hit_sphere(cast_ray,first_sphere)) {
            std::cout << "Hit Sphere" << std::endl;
            //color red
          } else {
            continue;
            //color white
          }
      }
  }
  return 0;
}
