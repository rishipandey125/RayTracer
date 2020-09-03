#include "render.cpp"
#include <sstream>

int main() {
  point camera_origin(0,0.8,0.1);
  point look_at(0,0,-1);
  float aspect_ratio = 16.0/9.0;
  float start_fov = 90;
  float aperture = 0;
  camera cam(camera_origin,look_at, aspect_ratio,start_fov,aperture);

  std::string folder_name = "/Users/rishipandey125/Desktop/RayTracedContent/";

  int frame_num = 1;
  float end_fov = 60;
  for (int x = 0; x < 72; x++) {
    std::ostringstream num;
    frame_num += 1;
    num<<frame_num;
    std::string frame_name = folder_name+"frame"+num .str()+".ppm";
    cam.vertical_fov = start_fov - ((start_fov-end_fov)*(x/72));
    render_frame(cam,frame_name);
  }
  return 0;
}
