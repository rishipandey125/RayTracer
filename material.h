#ifndef MATERIAL_H
#define MATERIAL_H
#include "ray.h"
#include "vec.h"
#include "hit.h"

class material {
  public:
    material();
    material(color b_color);
    color base_color;
    ray scatter(hit &record);
};

#endif
