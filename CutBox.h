#ifndef CUT_BOX_H
#define CUT_BOX_H

#include "FiguraGeometrica.h"

class CutBox:public FiguraGeometrica{
    int x0,x1,y0,y1,z0,z1;

    public:
        CutBox(int x0_, int x1_, int y0_, int y1_, int z0_, int z1_);
        ~CutBox(){};

        void draw(Sculptor &sculptor);
};

#endif // CUT_BOX_H