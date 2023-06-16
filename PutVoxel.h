#ifndef PUT_VOXEL_H
#define PUT_VOXEL_H

#include "FiguraGeometrica.h"

class PutVoxel:public FiguraGeometrica{
    int x,y,z;

    public:
        PutVoxel(int x_, int y_, int z_, float r_, float g_, float b_, float a_);
        ~PutVoxel(){};

        void draw(Sculptor &sculptor);
};

#endif // PUT_VOXEL_H