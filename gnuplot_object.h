#ifndef GNUPLOT_OBJECT_H
#define GNUPLOT_OBJECT_H

#include "Dr3D_gnuplot_api.hh"

class Gnuplot_object
{
protected:
    drawNS::Draw3DAPI & gnuplot;
public:
    Gnuplot_object(drawNS::APIGnuPlot3D & g): gnuplot(g) {}
    virtual ~Gnuplot_object() {}
    virtual uint draw() = 0;
};

#endif // GNUPLOT_OBJECT_H