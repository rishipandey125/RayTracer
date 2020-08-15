#include "diffuse.h"

diffuse::diffuse(color b_color) {
  base_color = b_color;
}

ray diffuse::scatter(hit &record) {
  point h_point = record.hit_point;
  point target = h_point + record.object->get_normal_vector(h_point) + record.random_unit_vec;
  return ray(h_point,target-h_point);
}
