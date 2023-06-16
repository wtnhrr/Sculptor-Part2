#include "PutVoxel.h"

PutVoxel::PutVoxel(int x_, int y_, int z_, float r_, float g_, float b_, float a_){
  this -> x = x_; this -> y = y_; this -> z = z_;
  this -> r = r_; this -> g = g_; this -> b = b_; this -> a = a_;
}

void PutVoxel::draw(Sculptor &sculptor){
  sculptor.setColor(r, g, b, a);
  sculptor.putVoxel(x, y, z);
}