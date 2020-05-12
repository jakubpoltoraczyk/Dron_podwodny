#ifndef HEXAGONAL_PRISM
#define HEXAGONAL_PRISM

#include "solid.h"

class Hexagonal_prism: public Solid
{
protected:
    Vector<double,3> tab[12];
public:
    Hexagonal_prism(const Vector<double,3> * t, const Vector<double,3> & p, const Matrix<double,3> & m, const std::string & c, std::shared_ptr<drawNS::Draw3DAPI> g);
    virtual ~Hexagonal_prism() {}
    void draw()override;
};

#endif // HEXAGONAL_PRISM