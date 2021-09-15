#include "cutsphere.h"

CutSphere::CutSphere(int xc, int yc, int zc, int radius){
    this->xc=xc;
    this->yc=yc;
    this->zc=zc;
    this->radius=radius;
}

void CutSphere::draw(Sculptor &t){
    for(int i=0; i<=t.getNx(); i++){
        for(int j=0; j<=t.getNy(); j++){
            for(int k=0; k<=t.getNz(); k++){
                if((i-xc)*(i-xc)+(j-yc)*(j-yc)+(k-zc)*(k-zc)<=radius*radius){
                    t.cutVoxel(i,j,k);
                }
            }
        }
    }
}
