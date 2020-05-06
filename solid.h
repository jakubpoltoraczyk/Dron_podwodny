#ifndef SOLID_H
#define SOLID_H

#include "gnuplot_object.h"
#include "rotation_matrix.h"

class Solid: public Gnuplot_object
{
protected:
    Vector<double,3> center_point;
public:
    Solid(const Vector<double,3> & p,drawNS::APIGnuPlot3D & g): Gnuplot_object(g)
    {
        center_point=p;
    }
    virtual ~Solid() {}
    virtual uint draw() = 0; 
    virtual void move(uint id,double length,double high) = 0;
    virtual void rotate(const Rotation_matrix & mat) = 0;
};

#endif // SOLID_H