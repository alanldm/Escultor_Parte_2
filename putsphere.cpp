#include "putsphere.h"

PutSphere::PutSphere(int xc, int yc, int zc, int radius, int r, int g, int b){
    this->xc=xc;
    this->yc=yc;
    this->zc=zc;
    this->radius=radius;
    this->r=r;
    this->g=g;
    this->b=b;
}

void PutSphere::draw(Sculptor &t){
    t.setColor(r,g,b);
    for(int i=0; i<=t.getNx(); i++){
        for(int j=0; j<=t.getNy(); j++){
            for(int k=0; k<=t.getNz(); k++){
                if((i-xc)*(i-xc)+(j-yc)*(j-yc)+(k-zc)*(k-zc)<=radius*radius){
                    t.putVoxel(i,j,k);
                }
            }
        }
    }
}
