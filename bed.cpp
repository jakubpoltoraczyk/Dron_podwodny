#include "bed.h"

void Bed::draw()
{
    using std::vector;
    Vector<double,3> x = (dim[3]-dim[0])*0.1;
    Vector<double,3> y = (dim[1]-dim[0])*0.1;
    gnuplot->draw_surface(vector<vector<drawNS::Point3D>>
    {
        {dim[0],dim[0]+x,dim[0]+x*2,dim[0]+x*3,dim[0]+x*4,dim[0]+x*5,dim[0]+x*6,dim[0]+x*7,dim[0]+x*8,dim[0]+x*9,dim[0]+x*10},
        {dim[0]+y,dim[0]+x+y,dim[0]+y+x*2,dim[0]+y+x*3,dim[0]+y+x*4,dim[0]+y+x*5,dim[0]+y+x*6,dim[0]+y+x*7,dim[0]+y+x*8,dim[0]+y+x*9,dim[0]+y+x*10},
        {dim[0]+y*2,dim[0]+x+y*2,dim[0]+y*2+x*2,dim[0]+y*2+x*3,dim[0]+y*2+x*4,dim[0]+y*2+x*5,dim[0]+y*2+x*6,dim[0]+y*2+x*7,dim[0]+y*2+x*8,dim[0]+y*2+x*9,dim[0]+y*2+x*10},
        {dim[0]+y*3,dim[0]+x+y*3,dim[0]+y*3+x*2,dim[0]+y*3+x*3,dim[0]+y*3+x*4,dim[0]+y*3+x*5,dim[0]+y*3+x*6,dim[0]+y*3+x*7,dim[0]+y*3+x*8,dim[0]+y*3+x*9,dim[0]+y*3+x*10},
        {dim[0]+y*4,dim[0]+x+y*4,dim[0]+y*4+x*2,dim[0]+y*4+x*3,dim[0]+y*4+x*4,dim[0]+y*4+x*5,dim[0]+y*4+x*6,dim[0]+y*4+x*7,dim[0]+y*4+x*8,dim[0]+y*4+x*9,dim[0]+y*4+x*10},
        {dim[0]+y*5,dim[0]+x+y*5,dim[0]+y*5+x*2,dim[0]+y*5+x*3,dim[0]+y*5+x*4,dim[0]+y*5+x*5,dim[0]+y*5+x*6,dim[0]+y*5+x*7,dim[0]+y*5+x*8,dim[0]+y*5+x*9,dim[0]+y*5+x*10},
        {dim[0]+y*6,dim[0]+x+y*6,dim[0]+y*6+x*2,dim[0]+y*6+x*3,dim[0]+y*6+x*4,dim[0]+y*6+x*5,dim[0]+y*6+x*6,dim[0]+y*6+x*7,dim[0]+y*6+x*8,dim[0]+y*6+x*9,dim[0]+y*6+x*10},
        {dim[0]+y*7,dim[0]+x+y*7,dim[0]+y*7+x*2,dim[0]+y*7+x*3,dim[0]+y*7+x*4,dim[0]+y*7+x*5,dim[0]+y*7+x*6,dim[0]+y*7+x*7,dim[0]+y*7+x*8,dim[0]+y*7+x*9,dim[0]+y*7+x*10},
        {dim[0]+y*8,dim[0]+x+y*8,dim[0]+y*8+x*2,dim[0]+y*8+x*3,dim[0]+y*8+x*4,dim[0]+y*8+x*5,dim[0]+y*8+x*6,dim[0]+y*8+x*7,dim[0]+y*8+x*8,dim[0]+y*8+x*9,dim[0]+y*8+x*10},
        {dim[0]+y*9,dim[0]+x+y*9,dim[0]+y*9+x*2,dim[0]+y*9+x*3,dim[0]+y*9+x*4,dim[0]+y*9+x*5,dim[0]+y*9+x*6,dim[0]+y*9+x*7,dim[0]+y*9+x*8,dim[0]+y*9+x*9,dim[0]+y*9+x*10},
        {dim[0]+y*10,dim[0]+x+y*10,dim[0]+y*10+x*2,dim[0]+y*10+x*3,dim[0]+y*10+x*4,dim[0]+y*10+x*5,dim[0]+y*10+x*6,dim[0]+y*10+x*7,dim[0]+y*10+x*8,dim[0]+y*10+x*9,dim[0]+y*10+x*10}
    },color);
    gnuplot->redraw();
}