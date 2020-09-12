/*
Main Function for Ray-Tracer
Create Camera
Call render.cpp
Render Frames
*/
#include "render.cpp"
#include <sstream>

int main() {
  //Camera Parameters
  point camera_start(0,0.8,0.1);
  point camera_end(0,0,0.1);
  point look_at_start(0,0,-1.5);
  point look_at_end(1.2,0.0,-3.0);
  float aspect_ratio = 16.0/9.0;
  float start_fov = 90;
  float end_fov = 90;
  float start_apeture = 2.0;
  float end_apeture = 2.0;
  int total_frames = 72;
  camera cam(camera_start,camera_end,look_at_start,look_at_end,
            aspect_ratio,start_fov,end_fov,start_apeture,
            end_apeture,total_frames);

  //Capture and Render Frames
  std::string folder_name = "/Users/rishipandey125/Desktop/RayTracedContent/";
  while (!(cam.capture_complete)) {
    cam.next_capture();
    std::ostringstream num;
    num<<cam.frame_count;
    std::string frame_name = folder_name+num.str()+".ppm";
    render_frame(cam,frame_name);
    //single capture
    // if (true) {
    //   break;
    // }
  }
  return 0;
}
