#include "interpretador.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

using namespace std;

vector<FiguraGeometrica*> interpretador::parse(string filename){
    vector<FiguraGeometrica*> figs;
    string s, token;
    ifstream in;
    stringstream ss;
    in.open(filename.c_str());

    if(!in.is_open()){
        cout << "Erro ao abrir o arquivo!" << std::endl;
    }

    while(in.good()){
        getline(in, s);
        if(in.good()){
            ss.clear();
            ss.str(s);
            ss >> token;

            if(ss.good()){
                if(token.compare("dim")==0){
                    ss >> dimx >> dimy >> dimz;
                }else if(token.compare("putvoxel")==0){
                    int x, y, z;
                    ss >> x >> y >> z >> r >> g >> b;
                    figs.push_back(new PutVoxel(x,y,z,r,g,b));

                }else if(token.compare("cutvoxel")==0){
                    int x, y, z;
                    ss >> x >> y >> z;
                    figs.push_back(new CutVoxel(x,y,z));

                }else if(token.compare("putbox")==0){
                    int x0, x1, y0, y1, z0, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b;
                    figs.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b));

                }else if(token.compare("cutbox")==0){
                    int x0, x1, y0, y1, z0, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    figs.push_back(new CutBox(x0,x1,y0,y1,z0,z1));

                }else if(token.compare("putsphere")==0){
                    int xc, yc, zc, radius;
                    ss >> xc >> yc >> zc >> radius >> r >> g >> b;
                    figs.push_back(new PutSphere(xc,yc,zc,radius,r,g,b));

                }else if(token.compare("cutsphere")==0){
                    int xc, yc, zc, radius;
                    ss >> xc >> yc >> zc >> radius;
                    figs.push_back(new CutSphere(xc,yc,zc,radius));

                }else if(token.compare("putellipsoid")==0){
                    int xc, yc, zc, rx, ry, rz;
                    ss >> xc >> yc >> zc >> rx >> ry >> rz >> r >> g >> b;
                    figs.push_back(new PutEllipsoid(xc,yc,zc,rx,ry,rz,r,g,b));

                }else if(token.compare("cutellipsoid")==0){
                    int xc, yc, zc, rx, ry, rz;
                    ss >> xc >> yc >> zc >> rx >> ry >> rz;
                    figs.push_back(new CutEllipsoid(xc,yc,zc,rx,ry,rz));
                }
            }
        }
    }
    return figs;
}

interpretador::interpretador()
{

}

int interpretador::getDimx(){
    return dimx;
}

int interpretador::getDimy(){
    return dimy;
}

int interpretador::getDimz(){
    return dimz;
}
