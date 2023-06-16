#include "PutBox.h"

PutBox::PutBox(int x0_, int x1_, int y0_, int y1_, int z0_, int z1_, float r_, float g_, float b_, float a_){
    this -> x0 = x0_, this -> x1 = x1_;
    this -> y0 = y0_, this -> y1 = y1_;
    this -> z0 = z0_, this -> z1 = z1_;

    this -> r = r_;  this -> g  = g_ ; this -> b = b_; this -> a = a_;
}

void PutBox::draw(Sculptor &sculptor){
    sculptor.setColor(r, g, b, a);
    for(int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            for(int k = z0; k < z1; k++){
                sculptor.putVoxel(i, j, k);
            }
        }
    }
}