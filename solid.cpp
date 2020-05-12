#include "solid.h"

void Solid::rotate(double angle)
{
    erase_object();
    rot_mat.rotate_z(angle);
    draw();
}

void Solid::replace(const Vector<double,3> & vec)
{
    erase_object();
    center_point=vec;
    draw();
}