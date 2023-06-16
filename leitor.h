#ifndef LEITOR_H
#define LEITOR_H

#include <vector>
#include <string>
#include "figurageometrica.h"
#include "Sculptor.h"

class Leitor{
    int dimx, dimy, dimz;
    float r,g,b,a;

    public:
        Leitor();
        std::vector<FiguraGeometrica*> parse(std::string filename);

        int getDimx();
        int getDimy();
        int getDimz();

};

#endif