#include "diffuse.h"

diffuse::diffuse(color b_color) {
  base_color = b_color;
}

ray diffuse::scatter(hit &record) {
  point target = record.hit_point + record.object.get_normal_vector(record.hit_point) + random_unit_vector();
  return ray(record.hit_point,target-record.hit_point);
}
