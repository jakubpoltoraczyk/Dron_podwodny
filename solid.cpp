#include "solid.h"

void Solid::rotate(double angle)
{
    gnuplot->erase_shape(id);
    rot_mat.rotate_z(angle);
    draw();
}

void Solid::replace(const Vector<double,3> & vec)
{
    gnuplot->erase_shape(id);
    center_point=vec;
    draw();
}