#ifndef MATERIAL_H
#define MATERIAL_H
#include "vec.h"
class material {
  public:
    color base_color;
};

class diffuse: public material {
  public:
    diffuse(color b_color);
    vec scatter(hit record);
    

};

class metal: public material {

};

#endif
