#include "solid.h"

void Solid::rotate(double angle)
{
    gnuplot->erase_shape(id);
    Rotation_matrix pom(rot_mat);
    double rad = M_PI * angle / 180;
    pom[0][0]=cos(rad);
    pom[1][1]=cos(rad);
    pom[0][1]=(-1)*sin(rad);
    pom[1][0]=sin(rad);
    rot_mat=Rotation_matrix(rot_mat*pom);
    draw();
}

void Solid::replace(const Vector<double,3> & vec)
{
    gnuplot->erase_shape(id);
    center_point+=rot_mat*vec;
    draw();
}