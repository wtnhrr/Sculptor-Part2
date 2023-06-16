#include "CutVoxel.h"

CutVoxel::CutVoxel(int x_, int y_, int z_){
    this -> x = x_; this -> y = y_; this -> z = z_;
}

void CutVoxel::draw(Sculptor &sculptor){
    sculptor.cutVoxel(x, y, z);
}