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
    // (-b-sqrt(disc))/2a = t (the smallest value t can be (from there you can calc the point))
    //point impact = casted_ray.origin + (t * casted_ray.direction)
    return true;
  }
  // return something else that indicates no point of hit
  return false;
}

int main() {
  // Image Details
  float aspect_ratio = 16.0/9.0;
  sphere first_sphere(point(0,0,-10),0.5);
  int image_width = 400;
  int image_height = (int)(image_width/aspect_ratio);

  //Camera Details
  point camera_origin(0,0,0);
  float viewport_height = 2.0;
  float viewport_width = viewport_height*aspect_ratio;
  float focal_length = 1.0; // sets viewport at z = -1
  float viewport_z = -1*focal_length;

  //Render Details
  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
  for (int j = image_height-1; j >= 0; j--) {
      float v = float(j)/image_height;
      float viewport_y = (viewport_height/2)-(v*viewport_height);
      for (int i = 0; i < image_width; i++) {
          float u = float(i)/image_width;
          point viewport_point((u*viewport_width)-(viewport_width/2),viewport_y,viewport_z);
          vec direction = viewport_point-camera_origin;
          ray cast_ray(camera_origin,direction);
          if (hit_sphere(cast_ray,first_sphere)) {
            output_color(color(1,0,0));
          } else {
            output_color(color(1,1,1));
          }
      }
  }
  return 0;
}
