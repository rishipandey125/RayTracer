#ifndef DIFFUSE_H
#define DIFFUSE_H
#include "material.h"
// #include "ray.h"
// #include "vec.h"
// #include "hit.h"

class diffuse : public material {
  public:
    ray scatter(hit &record);
};

#endif
