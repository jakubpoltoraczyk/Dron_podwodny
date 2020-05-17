#ifndef WATER_H
#define WATER_H

#include "surface.h"

class Water: public Surface
{
protected:
    Vector<double,3> wave;
public:
    Water(double high, double min_x, double max_x, double min_y, double max_y, double z, const std::string & c, std::shared_ptr<drawNS::Draw3DAPI> g): Surface(min_x,max_x,min_y,max_y,z,c,g)
    {
        double tab[3] = {0.0,0.0,high};
        wave = Vector<double,3>(tab);
    }
    void draw()override;
};

#endif // WATER_H