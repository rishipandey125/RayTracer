#include <iostream>
#include "vec.cpp"
#include "ray.cpp"

int main() {
  // const int image_width = 256;
  // const int image_height = 256;
  // std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
  // for (int j = image_height-1; j >= 0; j--) {
  //     for (int i = 0; i < image_width; i++) {
  //         auto r = double(i) / (image_width-1);
  //         auto g = double(j) / (image_height-1);
  //         auto b = 0.25;
  //         color pixel = vec(r,g,b);
  //         // pixel.print();
  //         int ir = static_cast<int>(255.999 * pixel.x);
  //         int ig = static_cast<int>(255.999 * pixel.y);
  //         int ib = static_cast<int>(255.999 * pixel.z);
  //
  //         std::cout << ir << ' ' << ig << ' ' << ib << '\n';
  //     }
  // }
  point origin(0,0,0);
  vec direction(2,1,2);
  ray first_ray(origin,direction);
  point val(first_ray.getPointAt(2));
  val.print();
  return 0;
}
