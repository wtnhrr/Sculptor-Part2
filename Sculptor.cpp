#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include "sculptor.h"


// Constructor
Sculptor :: Sculptor(int _nx, int _ny, int _nz){
    this->nx = _nx;
    this->ny = _ny;
    this->nz = _nz;
    r = g = b = a = 0.5;

    // Alocação Matriz 3D
    v = new Voxel**[nx];

    for(int i=0; i<nx; i++){
        v[i] = new Voxel *[ny];

        for(int j=0; j<ny; j++){
            v[i][j] = new Voxel[nz];

            for(int k=0; k<nz; k++){
                v[i][j][k].show = false;

                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
            }
        }
    }
}

// Destrutor
Sculptor ::~Sculptor(){

    // Liberacao da memoria alocada para a Matriz
    for (int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            delete[] v[i][j];
        }
        delete[] v[i];
    }
    delete[] v;
    nx = ny = nz = 0;
}

// Cores
void Sculptor ::setColor(float mr, float mg, float mb, float ma){
    r = mr;
    g = mg;
    b = mb;
    a = ma;
}

// Ativa Voxel Posição
void Sculptor ::putVoxel(int mx, int my, int mz){
    v[mx][my][mz].show = true;
    v[mx][my][mz].r = r;
    v[mx][my][mz].g = g;
    v[mx][my][mz].b = b;
    v[mx][my][mz].a = a;
}

// Desativa voxel posicão
void Sculptor ::cutVoxel(int mx, int my, int mz){
    v[mx][my][mz].show = false;
}

int Sculptor::getDimx(){
    return nx;
}
int Sculptor::getDimy(){
    return ny;
}
int Sculptor::getDimz(){
    return nz;
}

// Criacao do arquivo .OFF
void Sculptor::writeOFF(char *filename){
    std::ofstream fout;
    fixed(fout);

    int Nvertices = 0;
    int Nfaces = 0;
    int aux = 0;

    fout.open(filename);

    if (fout.is_open()){
        std::cout << "Arquivo salvo\n";
    }
    else{
        std::cout << "Falha ao abrir aquivo\n";
        exit(1);
    }

    fout << "OFF" << std::endl;

    for (int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            for (int k = 0; k < nz; k++){
                if (v[i][j][k].show == true){
                    Nvertices = Nvertices + 8;
                    Nfaces = Nfaces + 6;
                }
            }
        }
    }

    fout << Nvertices << " " << Nfaces << " " << 0 << std::endl;

    for (int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            for (int k = 0; k < nz; k++){
                if (v[i][j][k].show == true){
                    fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
                    fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
                    fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
                    fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
                    fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
                    fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
                    fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
                    fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
                }
            }
        }
    }

    for (int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            for (int k = 0; k < nz; k++){
                if (v[i][j][k].show == true){
                    fout << 4 << " " << aux + 0 << " " << aux + 3 << " " << aux + 2 << " " << aux + 1 << " " << v[i][j][k].r << " "
                         << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    fout << 4 << " " << aux + 4 << " " << aux + 5 << " " << aux + 6 << " " << aux + 7 << " " << v[i][j][k].r << " "
                         << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    fout << 4 << " " << aux + 0 << " " << aux + 1 << " " << aux + 5 << " " << aux + 4 << " " << v[i][j][k].r << " "
                         << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    fout << 4 << " " << aux + 0 << " " << aux + 4 << " " << aux + 7 << " " << aux + 3 << " " << v[i][j][k].r << " "
                         << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    fout << 4 << " " << aux + 3 << " " << aux + 7 << " " << aux + 6 << " " << aux + 2 << " " << v[i][j][k].r << " "
                         << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    fout << 4 << " " << aux + 1 << " " << aux + 2 << " " << aux + 6 << " " << aux + 5 << " " << v[i][j][k].r << " "
                         << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    aux = aux + 8;
                }
            }
        }
    }

    if (fout.is_open()){
        std::cout << "Arquivo.OFF salvo!" << std::endl;
    }
    fout.close();
}