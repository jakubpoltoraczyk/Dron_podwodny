#ifndef BED_H
#define BED_H

#include "surface.h"

class Bed: public Surface
{
public:
    Bed(double min_x, double max_x, double min_y, double max_y, double z,const std::string & c, std::shared_ptr<drawNS::Draw3DAPI> g): Surface(min_x,max_x,min_y,max_y,z,c,g) {}
    void draw()override;
};

#endif // BED_H