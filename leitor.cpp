#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

#include "PutVoxel.h"
#include "PutSphere.h"
#include "PutEllipsoid.h"
#include "PutBox.h"

#include "CutVoxel.h"
#include "CutSphere.h"
#include "CutEllipsoid.h"
#include "CutBox.h"

#include "leitor.h"

Leitor::Leitor(){
    
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

std::vector<FiguraGeometrica *> Leitor::parse(std::string file_path){
    std::vector<FiguraGeometrica *> figs;
    std::ifstream fin;
    std::stringstream ss;
    std::string s, token;

    fin.open(file_path.c_str());

    if (!fin.is_open()){
        std::cout << "Erro ao ler o arquivo." << std::endl;
        exit(1);
    }

    while (fin.good()){
        std::getline(fin, s);
        
        ss.clear();
        ss.str(s);
        ss >> token;

        if (ss.good()){
            if (token.compare("d") == 0){
                ss >> dimx >> dimy >> dimz;
            }

            else if (token.compare("putvoxel") == 0){
                int x, y, z;
                ss >> x >> y >> z >> r >> g >> b >> a;
                figs.push_back(new PutVoxel(x, y, z, r, g, b, a));
            }

            else if (token.compare("putbox") == 0){
                int x0, x1, y0, y1, z0, z1;
                ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
            }

            else if (token.compare("putsphere") == 0){
                int xcenter, ycenter, zcenter, radius;
                ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
                figs.push_back(new PutSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
            }

            else if (token.compare("putellipsoid") == 0){
                int xcenter, ycenter, zcenter, rx, ry, rz;
                ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
                figs.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
            }

            else if (token.compare("cutvoxel") == 0){
                int x, y, z;
                ss >> x >> y >> z >> r >> g >> b >> a;
                figs.push_back(new CutVoxel(x, y, z));
            }
            
            else if (token.compare("cutbox") == 0){
                int x0, x1, y0, y1, z0, z1;
                ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                figs.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
            }

            else if (token.compare("cutsphere") == 0){
                int xcenter, ycenter, zcenter, radius;
                ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
                figs.push_back(new CutSphere(xcenter, ycenter, zcenter, radius));
            }

            else if (token.compare("cutellipsoid") == 0){
                int xcenter, ycenter, zcenter, rx, ry, rz;
                ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
                figs.push_back(new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
            }
        }
    }
    return figs;
}