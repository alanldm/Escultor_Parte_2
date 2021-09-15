#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"

class CutSphere: public FiguraGeometrica{
protected:
    int xc, yc, zc, radius;
public:
    CutSphere(int xc, int yc, int zc, int radius);
    ~CutSphere(){};
    void draw(Sculptor &t);
};

#endif // CUTSPHERE_H
