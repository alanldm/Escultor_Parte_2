#ifndef SCULPTOR_H
#define SCULPTOR_H
#include <fstream>

struct Voxel{
    float r, g, b;
    bool isOn;
};

class Sculptor{
protected:
    Voxel ***v;
    int nx, ny, nz;
    float r, g, b;
public:
    Sculptor(int nx, int ny, int nz);
    ~Sculptor();
    void setColor(float r, float g, float b);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void writeOFF(char *filename);
    int getNx();
    int getNy();
    int getNz();
};

#endif // SCULPTOR_H
