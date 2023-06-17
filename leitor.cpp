#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

#include "putVoxel.h"
#include "putSphere.h"
#include "putEllipsoid.h"
#include "putBox.h"

#include "cutVoxel.h"
#include "cutSphere.h"
#include "cutEllipsoid.h"
#include "cutBox.h"

#include "leitor.h"

Leitor::Leitor(){

}

std::vector<FiguraGeometrica *> Leitor::parse(std::string filename){
    std::vector<FiguraGeometrica *> figs;
    std::ifstream fin;      // ler dados de um aquivo de entrada
    std::stringstream ss;   // armazenar e manipular dados de strings
    std::string s, token;   // auxiliares para armazenar valores durante a execução

    fin.open(filename.c_str());

    if (!fin.is_open()){
        std::cout << "Erro ao ler o arquivo." << std::endl;
        exit(0);
    }

    while (fin.good()){
        std::getline(fin, s);   // ler cada linha com fin e armazenando em s
        ss.clear();             // limpar o estado
        ss.str(s);              // iniciar o fluxo de entrada para extração de dados
        ss >> token;            // extrai o primeiro token e armazena na variavel

        if (ss.good()){
            if (token.compare("dim") == 0){
                ss >> dimx >> dimy >> dimz;
            }

            else if (token.compare("putVoxel") == 0){
                int x, y, z;
                ss >> x >> y >> z >> r >> g >> b >> a;
                figs.push_back(new putVoxel(x, y, z, r, g, b, a));
            }

            else if (token.compare("putBox") == 0){
                int x0, x1, y0, y1, z0, z1;
                ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                figs.push_back(new putBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
            }

            else if (token.compare("putSphere") == 0){
                int xcenter, ycenter, zcenter, radius;
                ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
                figs.push_back(new putSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
            }

            else if (token.compare("putEllipsoid") == 0){
                int xcenter, ycenter, zcenter, rx, ry, rz;
                ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
                figs.push_back(new putEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
            }

            else if (token.compare("cutVoxel") == 0){
                int x, y, z;
                ss >> x >> y >> z >> r >> g >> b >> a;
                figs.push_back(new cutVoxel(x, y, z));
            }
            
            else if (token.compare("cutBox") == 0){
                int x0, x1, y0, y1, z0, z1;
                ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                figs.push_back(new cutBox(x0, x1, y0, y1, z0, z1));
            }

            else if (token.compare("cutSphere") == 0){
                int xcenter, ycenter, zcenter, radius;
                ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
                figs.push_back(new cutSphere(xcenter, ycenter, zcenter, radius));
            }

            else if (token.compare("cutEllipsoid") == 0){
                int xcenter, ycenter, zcenter, rx, ry, rz;
                ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
                figs.push_back(new cutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
            }
        }
    }

    return (figs);
}

int Leitor::getDimx(){ 
    return dimx; 
}
int Leitor::getDimy(){
    return dimy;
}
int Leitor::getDimz(){
    return dimz;
}