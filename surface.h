#ifndef SURFACE_H
#define SURFACE_H

#include "drawing_interface.h"
#include "vector.h"

class Surface: public Drawing_interface
{
protected:
    Vector<double,3> dim[4];
public:
    Surface(double min_x, double max_x, double min_y, double max_y, double z, const std::string & c, std::shared_ptr<drawNS::Draw3DAPI> g): Drawing_interface(c,g)
    {
        double pom[4][3] = {{min_x,min_y,z},{min_x,max_y,z},{max_x,max_y,z},{max_x,min_y,z}};
        for(int i=0;i<4;++i)
            dim[i]=Vector<double,3>(pom[i]);
    }
    virtual ~Surface() {}
    virtual void draw() = 0;
};

#endif // SURFACE_H