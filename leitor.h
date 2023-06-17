#ifndef LEITOR_H
#define LEITOR_H

#include <vector>
#include <string>

#include "figurageometrica.h"
#include "sculptor.h"

class Leitor{
    int dimx, dimy, dimz;
    float r, g, b, a;

public:
    Leitor();
    std::vector<FiguraGeometrica *> parse(std::string filename); // gerar uma lista do que quero desenhar

    int getDimx();
    int getDimy();
    int getDimz();
};

#endif // LEITOR_H