#ifndef CUT_SPHERE_H
#define CUT_SPHERE_H

#include "FiguraGeometrica.h"

class CutSphere:public FiguraGeometrica{
    int xcenter, ycenter, zcenter, radius;

    public:
        CutSphere(int xcenter_, int ycenter_, int zcenter_, int radius_);
        ~CutSphere(){};

        void draw(Sculptor &sculptor);
};

#endif // CUT_SPHERE_H