#include "putellipsoid.h"

PutEllipsoid::PutEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz, int r, int g, int b){
    this->xc=xc;
    this->yc=yc;
    this->zc=zc;
    this->rx=rx;
    this->ry=ry;
    this->rz=rz;
    this->r=r;
    this->g=g;
    this->b=b;
}

void PutEllipsoid::draw(Sculptor &t){
    t.setColor(r, g, b);
    if(rx!=0 && ry!=0 && rz!=0){
        for(int x=0; x<=t.getNx(); x++){
            for(int y=0; y<=t.getNy(); y++){
                for(int z=0; z<=t.getNz(); z++){
                    if((float)((((x-xc)*(x-xc))/(rx*rx))+(((y-yc)*(y-yc))/(ry*ry))+(((z-zc)*(z-zc))/(rz*rz)))<=1){
                        t.putVoxel(x, y ,z);
                    }
                }
            }
        }
    } else if(rx==0){
        for(int y=0; y<=t.getNy(); y++){
            for(int z=0; z<=t.getNz(); z++){
                if((float)((((y-yc)*(y-yc))/(ry*ry))+(((z-zc)*(z-zc))/(rz*rz)))<=1){
                    t.putVoxel(xc, y, z);
                }
            }
        }
    } else if(ry==0){
        for(int x=0; x<=t.getNx(); x++){
            for(int z=0; z<=t.getNz(); z++){
                if((float)((((x-xc)*(x-xc))/(rx*rx))+(((z-zc)*(z-zc))/(rz*rz)))<=1){
                   t.putVoxel(x, yc, z);
                }
            }
        }
    } else if(rz==0){
        for(int x=0; x<=t.getNx(); x++){
            for(int y=0; y<=t.getNy(); y++){
                if((float)((((x-xc)*(x-xc))/(rx*rx))+(((y-yc)*(y-yc))/(ry*ry)))<=1){
                    t.putVoxel(x, y, zc);
                }
            }
        }
    }
}
