#include "putvoxel.h"

PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b){
    this->x=x;
    this->y=y;
    this->z=z;
    this->r=r;
    this->g=g;
    this->b=b;
}

void PutVoxel::draw(Sculptor &t){
    t.setColor(r, g, b);
    t.putVoxel(x, y, z);
}
