#include "cutEllipsoid.h"

cutEllipsoid::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> rx = rx; 
    this -> ry = ry;
    this -> rz = rz;
}

void cutEllipsoid::draw(Sculptor &s){
    s.setColor(r, g, b, a);

    for(int x = xcenter - rx; x < xcenter + rx; x++){
        for(int y = ycenter - ry; y < ycenter + ry; y++){
            for(int z = zcenter - rz; z < zcenter + rz; z++){
                float distance = ((x-xcenter)/2.0) * ((x-xcenter)/2.0 ) / ((rx/2.0)*(rx/2.0)) +
                ((y-ycenter)/2.0) * ((y-ycenter)/2.0) / ((ry/2.0)*(ry/2.0)) +
                ((z-zcenter)/2.0) * ((z-zcenter)/2.0 ) / ((rz/2.0)*(rz/2.0));

                if((distance <= 1)){
                    s.cutVoxel(x, y, z);
                }
            }
        }
    }
}