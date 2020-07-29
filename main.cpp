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

bool hit_sphere(ray &casted_ray,const sphere &object) {
  vec ac = casted_ray.origin - object.center;
  float a = casted_ray.direction.dot(casted_ray.direction);
  float b = 2 * casted_ray.direction.dot(ac);
  float c = ac.dot(ac) - (object.radius*object.radius);
  float discriminant = (b*b) - (4*a*c);
  if (discriminant > 0) {
    return true;
  }
  return false;
}

int main() {
  //Image Details
  float aspect_ratio = 16.0/9.0;
  point sphere_center(0,0,-1.5);
  sphere first_sphere(sphere_center,0.5);
  int image_width = 400;
  int image_height = (int)(image_width/aspect_ratio);

  //Camera Details
  point camera_origin(0,0,0);
  float viewport_height = 2.0;
  float viewport_width = viewport_height*aspect_ratio;
  float focal_length = 1.0; // sets viewport at z = -1
  int sphere_count = 0;
  int not_hit_count = 0;
  //Render Details
  // set viewport rays to cast through image loop
  // std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
  //we need to fix our vec class it is not working that well
  point viewport_point;
  for (int j = image_height-1; j >= 0; j--) {
      for (int i = 0; i < image_width; i++) {
          float u = i/image_width;
          float v = j/image_height;
          viewport_point = point((u*viewport_width)-(viewport_width/2),(v*viewport_height)-(viewport_height/2),-1*focal_length);
          viewport_point.print();
          //creates the same viewport point everytime, this ends up creating the same ray everytime, meaning we never get a hit because we are shooting the same ray
          vec direction = viewport_point-camera_origin;
          ray cast_ray(camera_origin,direction);
          if (hit_sphere(cast_ray,first_sphere)) {
            sphere_count += 1;
            //color red
          } else {
            not_hit_count += 1;
            //color white
          }
      }
  }
  std::cout << "Sphere Hit Count: " << sphere_count << std::endl;
  std::cout << "Not Hit Count: " << not_hit_count << std::endl;

  return 0;
}
