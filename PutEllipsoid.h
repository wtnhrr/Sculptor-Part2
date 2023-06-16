#ifndef PUT_ELLIPSOID_H
#define PUT_ELLIPSOID_H

#include "FiguraGeometrica.h"


class PutEllipsoid:public FiguraGeometrica{
    int xcenter, ycenter, zcenter, rx, ry, rz;

    public:
        PutEllipsoid(int xcenter_, int ycenter_, int zcenter_, int rx_, int ry_, int rz_, float r_, float g_, float b_, float a_);
        ~PutEllipsoid(){};

        void draw(Sculptor &sculptor);
  };

#endif // PUT_ELLIPSOID_H