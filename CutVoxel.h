#ifndef CUT_VOXEL_H
#define CUT_VOXEL_H

#include "FiguraGeometrica.h"

class CutVoxel:public FiguraGeometrica{
    int x, y, z;

    public:
        CutVoxel(int x_, int y_, int z_);
        ~CutVoxel(){};

        void draw(Sculptor &sculptor);
};

#endif // CUT_VOXEL_H