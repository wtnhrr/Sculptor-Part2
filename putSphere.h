#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figurageometrica.h"
#include "sculptor.h"

class putSphere : public FiguraGeometrica{
  int xcenter, ycenter, zcenter, radius;

public:
  putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
  void draw(Sculptor &s);
  ~putSphere(){};
};

#endif // PUTSPHERE_H