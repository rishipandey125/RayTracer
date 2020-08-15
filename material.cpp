#include "material.h"

material::material() {
  base_color = color(0,0,0);
}

material::material(color b_color) {
  base_color = b_color;
}

ray material::scatter(hit &record) {
  return ray(record.hit_point,record.hit_point);
}
