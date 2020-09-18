#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include "vec.cpp"
#include "ray.cpp"
#include "sphere.cpp"
#include "camera.cpp"
#include "material.h"
#include "hit.h"
#include "random.cpp"
//RENDER CPP FILE
/*
Traces Ray through the Scene
@param casted_ray: ray casted from camera through viewport
@param objects: data structure of all spheres in the scene
@param depth: number of bounces for ray tracing
*/

color trace(ray casted_ray, std::vector <sphere> objects, int depth) {
  if (depth <= 0) {
    return color(0,0,0);
  }
  float closest = float(RAND_MAX);   //closest parametric value
  hit record;
  for (int i = 0; i < objects.size(); i++) {
    float t = objects[i].hit_sphere(casted_ray);
      if (t < closest && t > 0.0) {
        closest = t;
        point hit_point = casted_ray.get_point_at(t);
        record.success = true;
        record.hit_point = hit_point;
        record.object = &objects[i];
      }
  }

  if (record.success) {
    record.random_unit_vec = random_unit_vector();
    record.object_normal = record.object->get_normal_vector(record.hit_point)*(1/(record.object->radius));
    record.casted_ray_direction = (casted_ray.direction);
    if (record.object->sphere_material->scatter(record)) {
      return trace(record.next_ray,objects,depth-1)*record.object->sphere_material->base_color;
    } else {
      return color(0,0,0);
    }
  }

  //gradient sky (global illumination)
  vec unit_direction = casted_ray.direction;
  unit_direction.unit();
  float val = (unit_direction.y+1.0)/2.0;
  return color(1.0, 1.0, 1.0)*(1-val) + color(0.5, 0.7, 1.0)*val;
}

//Output Color Function
color output_color(color &pixel, int samples) {
  float ratio = 1.0/float(samples);
  color output_pixel = pixel*ratio;
  //Gamma Correction gamma=2.0
  output_pixel.root();
  output_pixel.clamp();
  return output_pixel;
}

void render_frame(camera &cam,std::string file_name) {
  std::ofstream ofs;
  ofs.open(file_name,std::ios::out | std::ios::binary);

  //Initialize Materials
  diffuse world_mat(color(.88,0.76,0.82));
  metal gold(color(0.78,0.46,0.2),0.5);
  metal met(color(0.8,0.8,0.8),0.3);
  metal rose_gold(color(0.718,.431,.475),0.7);
  diffuse first(color(.49,0.51,0.7215));
  diffuse second(color(.294,.561,.549));
  diffuse third(color(0.38,.247,.459));
  dielectric glass_mat(1.5);

  //Initialize Spheres
  sphere world(point(0,-100.5,-1),100,&world_mat);
  sphere center_front(point(0,-0.2,-0.2),0.3,&glass_mat);
  sphere center_front_inside(point(0,-0.2,-0.2),-0.29,&glass_mat);
  sphere center(point(0.0,0.0,-1),0.5,&met);
  sphere center_back(point(0,0.5,-2.5),1.0,&third);
  sphere right(point(1,0.0,-1),0.5,&first);
  sphere left(point(-1,0.0,-1),0.5,&first);
  sphere right2(point(1.5,-0.2,-0.2),0.3,&rose_gold);
  sphere left2(point(-1.5,-0.2,-0.2),0.3,&rose_gold);
  sphere right3(point(0.6,-0.2,0.1),0.3,&second);
  sphere left3(point(-0.6,-0.2,0.1),0.3,&second);
  std::vector <sphere> spheres = {world,center_front,center_front_inside,center,center_back,right,left,right2,left2,right3,left3};

  int image_width = 1000;
  int image_height = (int)(image_width/cam.aspect_ratio);
  int samples = 1;
  //Render Details (Iterate and Create Image)
  ofs << "P3 \n" << image_width << ' ' << image_height << "\n255\n" << std::endl;
    for (int j = image_height-1; j >= 0; j--) {
      for (int i = 0; i < image_width; i++) {
          color pixel;
          //Anti-Aliasing
          for (int s = 0; s < samples; s++) {
            float u = (float(i) + random_float())/image_width;
            float v = (float(j) + random_float())/image_height;
            ray cast_ray = cam.get_ray(u,v);
            pixel = pixel + trace(cast_ray,spheres,50);
          }
        color output = output_color(pixel,samples);
        int r = static_cast<int>(255 * output.x);
        int g = static_cast<int>(255 * output.y);
        int b = static_cast<int>(255 * output.z);
        ofs << r << ' ' << g << ' '<< b << std::endl;
      }
  }
  ofs.flush();
  ofs.close();
}
