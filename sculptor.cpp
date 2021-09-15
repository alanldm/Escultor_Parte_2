#include "sculptor.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>

int Sculptor::getNx(){
    return nx;
}

int Sculptor::getNy(){
    return ny;
}

int Sculptor::getNz(){
    return nz;
}

Sculptor::Sculptor(int nx, int ny, int nz){
    this->nx=nx;
    this->ny=ny;
    this->nz=nz;
    v = new Voxel**[nx];
    for(int i=0; i<nx; i++){
        v[i] = new Voxel*[ny];
        for(int j=0; j<ny; j++){
            v[i][j] = new Voxel[nz];
        }
    }
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                v[i][j][k].isOn=false;
            }
        }
    }
}

Sculptor::~Sculptor(){
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            delete[] v[i][j];
        }
    }
    for(int i=0; i<nx; i++){
        delete[] v[i];
    }
    delete[] v;

}

void Sculptor::setColor(float r, float g, float b){
    this->r=r;
    this->g=g;
    this->b=b;
}

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn=true;
    v[x][y][z].r=r;
    v[x][y][z].g=g;
    v[x][y][z].b=b;
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn=false;
}

void Sculptor::writeOFF(char *filename){
    int contador=0;
    std::ofstream file;
    file.open(filename);
    if(!file.is_open()){
        exit(0);
    }

    file << "OFF" << std::endl;

    for(int x=0; x<nx; x++){
        for(int y=0; y<ny; y++){
            for(int z=0; z<nz; z++){
                if(v[x][y][z].isOn){
                    contador++;
                }
            }
        }
    }

    file << contador*8 << " " << contador*6 << " " << "0 " << std::endl;
    float largura = 0.5;

    for(int x=0; x<nx; x++){
        for(int y=0; y<ny; y++){
            for(int z=0; z<nz; z++){
                if(v[x][y][z].isOn){
                    file << x - largura << " " << y + largura << " " << z - largura << std::endl;
                    file << x - largura << " " << y - largura << " " << z - largura << std::endl;
                    file << x + largura << " " << y - largura << " " << z - largura << std::endl;
                    file << x + largura << " " << y + largura << " " << z - largura << std::endl;
                    file << x - largura << " " << y + largura << " " << z + largura << std::endl;
                    file << x - largura << " " << y - largura << " " << z + largura << std::endl;
                    file << x + largura << " " << y - largura << " " << z + largura << std::endl;
                    file << x + largura << " " << y + largura << " " << z + largura << std::endl;
                }
            }
        }
    }

    int vertice;
    contador=0;

    for(int x=0; x<nx; x++){
        for(int y=0; y<ny; y++){
            for(int z=0; z<nz; z++){
                if(v[x][y][z].isOn){
                    vertice=8*contador;
                    file << "4 " << vertice << " " << vertice+3 << " " << vertice+2 << " " << vertice+1 << " " << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << std::endl;
                    file << "4 " << vertice+4 << " " << vertice+5 << " " << vertice+6 << " " << vertice+7 << " " << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << std::endl;
                    file << "4 " << vertice << " " << vertice+1 << " " << vertice+5 << " " << vertice+4 << " " << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << std::endl;
                    file << "4 " << vertice << " " << vertice+4 << " " << vertice+7 << " " << vertice+3 << " " << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << std::endl;
                    file << "4 " << vertice+3 << " " << vertice+7 << " " << vertice+6 << " " << vertice+2 << " " << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << std::endl;
                    file << "4 " << vertice+1 << " " << vertice+2 << " " << vertice+6 << " " << vertice+5 << " " << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << std::endl;
                    contador++;
                }
            }
        }
    }
    file.close();
}
