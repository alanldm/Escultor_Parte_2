#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"


class FiguraGeometrica{
protected:
    float r, g, b;
public:
    virtual ~FiguraGeometrica(){};
    virtual void draw(Sculptor &t)=0;
};

#endif // FIGURAGEOMETRICA_H
