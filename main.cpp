#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "vec.cpp"
#include "ray.cpp"
#include "sphere.cpp"
#include "camera.cpp"
#include "material.h"
#include "hit.h"

//Generates Random Float between 0 and 1
float random_float() {
  return ((float) rand()/RAND_MAX);
}

//Generates Random Float between min and max
float random_float(float min, float max) {
  return min + ((max-min)*random_float());
}

//Creates a random unit vector from the unit sphere
vec random_unit_vector() {
  float a = random_float(0.0,2.0*M_PI);
  float z = random_float(-1.0,1.0);
  float r = sqrt(1-(z*z));
  return vec(r*cos(a),r*sin(a),z);
}

/*
Traces Ray through the Scene
@param casted_ray: ray casted from camera through viewport
@param objects: data structure of all spheres in the scene
@param depth: number of bounces for ray tracing
//reflect vector (v_in - (2 * dot(v_in,normal) * normal))
*/
color trace(ray casted_ray, std::vector <sphere> objects, int depth) {
  if (depth <= 0) {
    return color(0,0,0);
  }
  float closest = float(RAND_MAX);   //closest parametric value
  hit record;
  for (int i = 0; i < objects.size(); i++) {
    float t = objects[i].hit_sphere(casted_ray);
    if (t > 0.0) {
      if (t < closest) {
        closest = t;
        point hit_point = casted_ray.get_point_at(t);
        record.success = true;
        record.hit_point = hit_point;
        record.object = objects[i];
      }
    }
  }
  //CREATE MATERIAL CLASS BEFORE TESTING
  if (record.success) {
    record.random_unit_vec = random_unit_vector();
    ray next_ray = record.object.sphere_material.scatter(record);
    return trace(next_ray,objects,depth-1)*record.object.sphere_material.base_color;
    //reflected ray metal
    // vec v = casted_ray.direction;
    // vec n = record.object.get_normal_vector(record.hit_point);
    // float product  = v.dot(n)*2.0;
    // vec reflect = v - (n*product);


    //randomized target diffuse
      // point target = record.hit_point + record.object.get_normal_vector(record.hit_point) + random_unit_vector();
    //recursive ray call
    // if (reflect.dot(n) > 0)
      // return trace(ray(record.hit_point,reflect),objects,depth-1)*record.object.sphere_color;

    // return trace(ray(record.hit_point,target-record.hit_point),objects,depth-1)*record.object.sphere_color;
  }

  //gradient sky (global illumination)
  vec unit_direction = casted_ray.direction;
  unit_direction.unit();
  float val = (unit_direction.y+1.0)/2.0;
  return color(1.0, 1.0, 1.0)*(1-val) + color(0.5, 0.7, 1.0)*val;
}

//Output Color Function
void output_color(color &pixel, int samples) {
  float ratio = 1.0/float(samples);
  color output_pixel = pixel*ratio;
  //Gamma Correction gamma=2.0
  output_pixel.root();
  output_pixel.clamp();
  int r = static_cast<int>(255 * output_pixel.x);
  int g = static_cast<int>(255 * output_pixel.y);
  int b = static_cast<int>(255 * output_pixel.z);
  std::cout << r << ' ' << g << ' ' << b << '\n';
}

int main() {
  camera cam;
  diffuse world_sphere_mat(color(.2,.2,.2));
  diffuse first_sphere_mat(color(1,0,0));
  sphere world_sphere(point(0,-100.5,-1),100,world_sphere_mat);
  sphere first_sphere(point(0.0,0.0,-1),0.5,first_sphere_mat);
  std::vector <sphere> spheres = {world_sphere,first_sphere};
  int image_width = 1000;
  int image_height = (int)(image_width/cam.aspect_ratio);
  int samples = 1;

  //Render Details (Iterate and Create Image)
  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
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
        output_color(pixel,samples);
      }
  }
  return 0;
}
