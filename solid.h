#ifndef SOLID_H
#define SOLID_H

#include "drawing_interface.h"
#include "rotation_matrix.h"

class Solid: public Drawing_interface
{
protected:
    Rotation_matrix rot_mat;
    Vector<double,3> center_point;
public:
    Solid(const Vector<double,3> & p, const Matrix<double,3> & m, drawNS::APIGnuPlot3D * g): Drawing_interface(g), rot_mat(m), center_point(p) {}
    virtual ~Solid() {}
    virtual uint draw() = 0; 
    virtual void move(uint id,double angle,double length) = 0;
    virtual void rotate(int id, double angle) = 0;
};

#endif // SOLID_H