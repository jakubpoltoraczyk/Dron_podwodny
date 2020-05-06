#ifndef CUBOID_H
#define CUBOID_H

#include "solid.h"
#include <cmath>

class Cuboid: public Solid
{
private:
    Vector<double,3> tab[8];
public:
    Cuboid(const Vector<double,3> * t, const Vector<double,3> & p, const Matrix<double,3> & m, drawNS::APIGnuPlot3D * g);
    uint draw();
    void move(uint id,double angle,double length);
    void rotate(int id, double angle);
};

#endif // CUBOID_H