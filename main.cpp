#include "render.cpp"
#include <sstream>

int main() {
  point camera_origin(0,0.8,0.1);
  point look_at(0,0,-1);
  float aspect_ratio = 16.0/9.0;
  float vertical_fov = 90;
  float aperture = 0;
  camera cam(camera_origin,look_at, aspect_ratio,vertical_fov,aperture);
  std::string folder_name = "/Users/rishipandey125/Desktop/RayTracedContent/";
  float frame_num = 1;
  std::ostringstream num;
  num<<frame_num;
  std::string frame_name = folder_name+"frame"+num .str()+".ppm";
  render_frame(cam,frame_name);
  return 0;
}
