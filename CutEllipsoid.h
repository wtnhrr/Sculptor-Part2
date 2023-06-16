#ifndef CUT_ELLIPSOID_H
#define CUT_ELLIPSOID_H

#include "FiguraGeometrica.h"

class CutEllipsoid:public FiguraGeometrica{
    int xcenter, ycenter, zcenter, rx, ry, rz;

    public:
        CutEllipsoid(int x_center_, int y_center_, int z_center_, int rx_, int ry_, int rz_);
        ~CutEllipsoid(){};

        void draw(Sculptor &sculptor);
};

#endif // CUT_ELLIPSOID_H