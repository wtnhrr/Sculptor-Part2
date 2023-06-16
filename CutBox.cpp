#include "CutBox.h"

CutBox::CutBox(int x0_, int x1_, int y0_, int y1_, int z0_, int z1_){
    this -> x0 = x1_, this -> x1 = x1_;
    this -> y0 = y0_, this -> y1 = y1_;
    this -> z0 = z0_, this -> z1 = z1_;
}

void CutBox::draw(Sculptor &sculptor){
    for(int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            for(int k = z0; k < z1; k++){
                sculptor.cutVoxel(i, j, k);
            }
        }
    }
}