#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"


class CutEllipsoid: public FiguraGeometrica{
protected:
    int xc, yc, zc, rx, ry, rz;
public:
    CutEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz);
    ~CutEllipsoid(){};
    void draw(Sculptor &t);
};

#endif // CUTELLIPSOID_H
