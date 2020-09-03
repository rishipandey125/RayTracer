#include "render.cpp"
#include <sstream>

int main() {
  point camera_origin(0,0.8,0.1);
  point look_at(0,0,-1);
  float aspect_ratio = 16.0/9.0;
  float start_fov = 90;
  float aperture = 0;

  std::string folder_name = "/Users/rishipandey125/Desktop/RayTracedContent/";

  int frame_num = 0;
  float end_fov = 60;
  for (int x = 0; x < 72; x++) {
    std::ostringstream num;
    frame_num += 1;
    num<<frame_num;
    std::string frame_name = folder_name+num.str()+".ppm";
    float vfov = start_fov - ((start_fov-end_fov)*(float(x)/72.0));
    camera cam(camera_origin,look_at, aspect_ratio,vfov,aperture);
    render_frame(cam,frame_name);
  }
  return 0;
}
