#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"

class PutEllipsoid: public FiguraGeometrica{
protected:
    int xc, yc, zc, rx, ry, rz;
public:
    PutEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz, int r, int g, int b);
    ~PutEllipsoid(){};
    void draw(Sculptor &t);
};

#endif // PUTELLIPSOID_H
