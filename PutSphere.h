#ifndef PUT_SPHERE_H
  #define PUT_SPHERE_H

 #include "FiguraGeometrica.h"

class PutSphere:public FiguraGeometrica{
    int xcenter, ycenter, zcenter, radius;
    
    public:

        PutSphere(int xcenter_, int ycenter_, int zcenter_, int radius_, float r_, float g_, float b_, float a_);
        ~PutSphere(){};

        void draw(Sculptor &sculptor);
};

#endif // PUT_SPHERE_H