#include "cutellipsoid.h"

CutEllipsoid::CutEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz){
    this->xc=xc;
    this->yc=yc;
    this->zc=zc;
    this->rx=rx;
    this->ry=ry;
    this->rz=rz;
}

void CutEllipsoid::draw(Sculptor &t){
    if(rx!=0 && ry!=0 && rz!=0){
        for(int x=0; x<=t.getNx(); x++){
            for(int y=0; y<=t.getNy(); y++){
                for(int z=0; z<=t.getNz(); z++){
                    if((float)((((x-xc)*(x-xc))/(rx*rx))+(((y-yc)*(y-yc))/(ry*ry))+(((z-zc)*(z-zc))/(rz*rz)))<=1){
                        t.cutVoxel(x, y ,z);
                    }
                }
            }
        }
    } else if(rx==0){
        for(int y=0; y<=t.getNy(); y++){
            for(int z=0; z<=t.getNz(); z++){
                if((float)((((y-yc)*(y-yc))/(ry*ry))+(((z-zc)*(z-zc))/(rz*rz)))<=1){
                    t.cutVoxel(xc, y, z);
                }
            }
        }
    } else if(ry==0){
        for(int x=0; x<=t.getNx(); x++){
            for(int z=0; z<=t.getNz(); z++){
                if((float)((((x-xc)*(x-xc))/(rx*rx))+(((z-zc)*(z-zc))/(rz*rz)))<=1){
                   t.cutVoxel(x, yc, z);
                }
            }
        }
    } else if(rz==0){
        for(int x=0; x<=t.getNx(); x++){
            for(int y=0; y<=t.getNy(); y++){
                if((float)((((x-xc)*(x-xc))/(rx*rx))+(((y-yc)*(y-yc))/(ry*ry)))<=1){
                    t.cutVoxel(x, y, zc);
                }
            }
        }
    }
}
