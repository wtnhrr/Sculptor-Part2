#include "CutSphere.h"

CutSphere::CutSphere(int xcenter_, int ycenter_, int zcenter_, int radius_){
    this -> xcenter = xcenter_;
    this -> ycenter = ycenter_;
    this -> zcenter = zcenter_;
    this -> radius   = radius_;
}

void CutSphere::draw(Sculptor &sculptor){
    for(int x = xcenter - radius; x < xcenter + radius; x++){
        for(int y = ycenter - radius; y < ycenter + radius; y++){
            for(int z = zcenter - radius; z < zcenter + radius; z++){
                float distance = ((x-xcenter)/2.0) * ((x-xcenter)/2.0 ) / ((radius/2.0)*(radius/2.0)) +
                ((y-ycenter)/2.0) * ((y-ycenter)/2.0) / ((radius/2.0)*(radius/2.0)) +
                ((z-zcenter)/2.0) * ((z-zcenter)/2.0 ) / ((radius/2.0)*(radius/2.0));

                if( distance < 1.0){
                    sculptor.cutVoxel(x, y, z);
                }
            }
        }
    }
}