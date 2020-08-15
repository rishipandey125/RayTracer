#ifndef DIFFUSE_H
#define DIFFUSE_H
#include "material.h"
#include "ray.h"
#include "vec.h"
#include "hit.h"

class diffuse : public material {
  public:
    diffuse(color b_color);
    color base_color;
    ray scatter(hit &record);
};

#endif