#ifndef SOLID_H
#define SOLID_H

#include "drawing_interface.h"
#include "rotation_matrix.h"

class Solid: public Drawing_interface
{
protected:
    Rotation_matrix rot_mat;
    Vector<double,3> center_point;
    double id;
public:
    Solid(const Vector<double,3> & p, const Matrix<double,3> & m, drawNS::APIGnuPlot3D * g): Drawing_interface(g), rot_mat(m), center_point(p), id(0){}
    virtual ~Solid() {}
    virtual void draw() = 0; 
    void replace(const Vector<double,3> & vec);
    void rotate(double angle);
};

#endif // SOLID_H