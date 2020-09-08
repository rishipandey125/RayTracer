#include "render.cpp"
#include <sstream>

int main() {
  point camera_origin(0,0.8,0.1);
  point look_at(0,0,-1);
  float aspect_ratio = 16.0/9.0;
  float start_fov = 90;
  float end_fov = 60;
  float apeture = 0;
  int total_frames = 72;
  camera cam(camera_origin,look_at,aspect_ratio,start_fov,end_fov,apeture,apeture,total_frames);

  std::string folder_name = "/Users/rishipandey125/Desktop/RayTracedContent/";
  while (!(cam.capture_complete)) {
    cam.next_capture();
    std::ostringstream num;
    num<<cam.frame_count;
    //frame count never updating
    std::string frame_name = folder_name+num.str()+".ppm";
    render_frame(cam,frame_name);
  }
  return 0;
}
