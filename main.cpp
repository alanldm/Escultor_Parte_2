#include <iostream>
#include "sculptor.h"
#include "interpretador.h"
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){

    Sculptor *s1;

    interpretador parser;

    vector<FiguraGeometrica*> figs;

    figs = parser.parse("D:/Input.txt");

    s1 = new Sculptor(parser.getDimx(), parser.getDimy(), parser.getDimz());

    for(size_t i=0; i<figs.size(); i++){
        figs[i]->draw(*s1);
    }

    s1->writeOFF((char*)"D:/Escultor_2.off");

    for(size_t i=0; i<figs.size(); i++){
        delete figs[i];
    }

    delete s1;

    return 0;
}
