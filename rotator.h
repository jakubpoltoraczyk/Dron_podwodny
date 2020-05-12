#ifndef ROTATOR_H
#define ROTATOR_H

#include "hexagonal_prism.h"

class Rotator: public Hexagonal_prism
{
public:
    Rotator(const Vector<double,3> * t, const Vector<double,3> & p, const Matrix<double,3> & m, const std::string & c, std::shared_ptr<drawNS::Draw3DAPI> g): Hexagonal_prism(t,p,m,c,g) {}
    void draw(const Vector<double,3> & point);
    void turn(double angle);
};

#endif // ROTATOR_H