#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include "figurageometrica.h"
#include <vector>
#include <string>


class interpretador{
protected:
    int dimx, dimy, dimz;
    float r, g, b;
public:
    interpretador();
    std::vector<FiguraGeometrica*> parse(std::string filename);
    int getDimx();
    int getDimy();
    int getDimz();
};

#endif // INTERPRETADOR_H
