#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "sculptor.h"
#include "leitor.h"
#include "putSphere.h"
#include "figurageometrica.h"

int main(){
    Sculptor *wf;

    Leitor parser;

    std::vector<FiguraGeometrica *> figs;

    figs = parser.parse("entrada.txt");

    wf = new Sculptor(parser.getDimx(), parser.getDimy(), parser.getDimz());

    for (size_t i = 0; i < figs.size(); i++){
        figs[i]->draw(*wf);
    }
    
    wf->writeOFF((char*) "zariman.off");

    for (size_t i = 0; i < figs.size(); i++){
        delete figs[i];
    }

    delete wf;

    return 0;
}