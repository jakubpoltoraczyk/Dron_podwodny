#ifndef CUBOID_H
#define CUBOID_H

#include "solid.h"
#include <ctime>

class Cuboid: public Solid
{
private:
    Vector<double,3> tab[8];
public:
    Cuboid(const Vector<double,3> * t,const Vector<double,3> & p,drawNS::APIGnuPlot3D & g);
    uint draw();
    void move(uint id,double length,double high);
    void rotate(const Rotation_matrix & mat) {;}
};

#endif // CUBOID_H