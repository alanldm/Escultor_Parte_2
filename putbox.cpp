#include "putbox.h"

PutBox::PutBox(int x0, int x1, int y0, int y1, int z0, int z1, int r, int g, int b){
    this->x0=x0;
    this->x1=x1;
    this->y0=y0;
    this->y1=y1;
    this->z0=z0;
    this->z1=z1;
    this->r=r;
    this->g=g;
    this->b=b;
}

void PutBox::draw(Sculptor &t){
    t.setColor(r, g, b);
    for(int i=x0; i<=x1; i++){
        for(int j=y0; j<=y1; j++){
            for(int k=z0; k<=z1; k++){
                t.putVoxel(i, j, k);
            }
        }
    }
}
