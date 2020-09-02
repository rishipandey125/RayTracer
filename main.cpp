#include "render.cpp"


int main() {
  point camera_origin(0,0.8,0.1);
  point look_at(0,0,-1);
  float aspect_ratio = 16.0/9.0;
  float vertical_fov = 60;
  float aperture = 0;
  camera cam(camera_origin,look_at, aspect_ratio,vertical_fov,aperture);
  render_frame(cam);
  return 0;
}
