#include "cuboid.h"

Cuboid::Cuboid(const Vector<double,3> * t,const Vector<double,3> & p,drawNS::APIGnuPlot3D & g): Solid(p,g)
{
    for(int i=0;i<8;++i)
        tab[i]=t[i];
} 

uint Cuboid::draw()
{
    using std::vector;
    uint id;
    id=gnuplot.draw_polyhedron(vector<vector<drawNS::Point3D>>{{tab[0],tab[1],tab[2],tab[3]},{tab[4],tab[5],tab[6],tab[7]}},"blue");
    gnuplot.redraw();
    return id;
}

void Cuboid::move(uint id,double length,double high)
{
    double l_counter = 0.0, h_counter = 0.0;
    for(;l_counter<length||h_counter<high;l_counter+=0.03,h_counter+=0.03)
    {
        for(int i=0;i<8;++i)
        {
            if(l_counter<length)
                tab[i][0]+=0.03;
            if(h_counter<high)
                tab[i][2]+=0.03;
        }
        gnuplot.erase_shape(id);
        id=draw();
        gnuplot.redraw();
    }
}