#include <iostream>
#include "vec.cpp"
#include "ray.cpp"

int main() {
  float aspect_ratio = 16.0/9.0;
  int image_width = 400;
  int image_height = (int)(image_width/aspect_ratio);
  point camera_origin(0,0,0);
  
  // std::cout << image_height << std::endl;

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
  for (int j = image_height-1; j >= 0; j--) {
      for (int i = 0; i < image_width; i++) {
          auto r = double(i) / (image_width-1);
          auto g = double(j) / (image_height-1);
          auto b = 0.25;
          color pixel = vec(r,g,b);
          int ir = static_cast<int>(255.999 * pixel.x);
          int ig = static_cast<int>(255.999 * pixel.y);
          int ib = static_cast<int>(255.999 * pixel.z);
          std::cout << ir << ' ' << ig << ' ' << ib << '\n';
      }
  }
  return 0;
}
