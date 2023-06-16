#include "PutEllipsoid.h"

PutEllipsoid::PutEllipsoid(int xcenter_, int ycenter_, int zcenter_, int rx_, int ry_, int rz_, float r_, float g_, float b_, float a_){
    this -> xcenter = xcenter_;
    this -> ycenter = ycenter_;
    this -> zcenter = zcenter_;
    this -> rx = rx_; 
    this -> ry = ry_;
    this -> rz = rz_;

    this -> r  = r_;  this -> g  = g_ ; this -> b = b_; this -> a = a_;
}

void PutEllipsoid::draw(Sculptor &sculptor){
  sculptor.setColor(r, g, b, a);
  for(int x = xcenter - rx; x < xcenter + rx; x++){
    for(int y = ycenter - ry; y < ycenter + ry; y++){
      for(int z = zcenter - rz; z < zcenter + rz; z++){
        float distance = ((x-xcenter)/2.0) * ((x-xcenter)/2.0 ) / ((rx/2.0)*(rx/2.0)) +
                         ((y-ycenter)/2.0) * ((y-ycenter)/2.0) / ((ry/2.0)*(ry/2.0)) +
                         ((z-zcenter)/2.0) * ((z-zcenter)/2.0 ) / ((rz/2.0)*(rz/2.0));

        if((distance <= 1)){
          sculptor.putVoxel(x, y, z);
        }
      }
    }
  }
}