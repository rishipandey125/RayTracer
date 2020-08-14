#include "diffuse.h"

diffuse::diffuse(color b_color) {
  base_color = b_color;
}

ray diffuse::scatter(hit &record, vec rand_unit_vec) {
  point target = record.hit_point + record.object.get_normal_vector(record.hit_point) + rand_unit_vec;
  return ray(record.hit_point,target-record.hit_point);
}
