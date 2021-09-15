#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"

class PutSphere: public FiguraGeometrica{
protected:
    int xc, yc, zc, radius;
public:
    PutSphere(int xc, int yc, int zc, int radius, int r, int g, int b);
    ~PutSphere(){};
    void draw(Sculptor &t);
};

#endif // PUTSPHERE_H
