#ifndef DRAWING_INTERFACE
#define DRAWING_INTERFACE

#include "Dr3D_gnuplot_api.hh"

class Drawing_interface
{
protected:
    std::shared_ptr<drawNS::Draw3DAPI> gnuplot;
public:
    Drawing_interface(drawNS::Draw3DAPI * g): gnuplot(g) {}
    virtual ~Drawing_interface() {}
    virtual uint draw() = 0;
};

#endif // DRAWING_INTERFACE