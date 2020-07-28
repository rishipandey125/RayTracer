#include <iostream>
#include "vec.cpp"
#include "ray.cpp"

int main() {
  float aspect_ratio = 16.0/9.0;
  //Image Details
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

          // auto r = double(i) / (image_width-1);
          // auto g = double(j) / (image_height-1);
          // auto b = 0.25;
          // color pixel = vec(r,g,b);
          // int ir = static_cast<int>(255.999 * pixel.x);
          // int ig = static_cast<int>(255.999 * pixel.y);
          // int ib = static_cast<int>(255.999 * pixel.z);
          // std::cout << ir << ' ' << ig << ' ' << ib << '\n';
      }
  }
  return 0;
}
