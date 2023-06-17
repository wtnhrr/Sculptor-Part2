#include "cutSphere.h"

cutSphere::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> radius  = radius;
}

void cutSphere::draw(Sculptor &s){
    for(int x = xcenter - radius; x < xcenter + radius; x++){
        for(int y = ycenter - radius; y < ycenter + radius; y++){
            for(int z = zcenter - radius; z < zcenter + radius; z++){
                float distance = ((x-xcenter)/2.0) * ((x-xcenter)/2.0 ) / ((radius/2.0)*(radius/2.0)) +
                ((y-ycenter)/2.0) * ((y-ycenter)/2.0) / ((radius/2.0)*(radius/2.0)) +
                ((z-zcenter)/2.0) * ((z-zcenter)/2.0 ) / ((radius/2.0)*(radius/2.0));

                if( distance < 1.0){
                    s.cutVoxel(x, y, z);
                }
            }
        }
    }
}