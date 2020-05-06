#include "cuboid.h"

Cuboid::Cuboid(const Vector<double,3> * t,const Vector<double,3> & p, const Matrix<double,3> & m, drawNS::APIGnuPlot3D * g): Solid(p,m,g)
{
    for(int i=0;i<8;++i)
        tab[i]=t[i];
} 

void Cuboid::draw()
{
    using std::vector;
    uint id;
    Cuboid pom(*this);
    for(int i=0;i<8;++i)
        pom.tab[i]=center_point+rot_mat*tab[i];
    id=gnuplot->draw_polyhedron(vector<vector<drawNS::Point3D>>{{pom.tab[0],pom.tab[1],pom.tab[2],pom.tab[3]},{pom.tab[4],pom.tab[5],pom.tab[6],pom.tab[7]}},"blue");
    gnuplot->redraw();
    gnuplot->erase_shape(id);
}

void Cuboid::move(double angle,double length)
{
    double move_z = sin(angle)*length/500;
    double move_x = cos(angle)*length/500;
    for(int counter=0;counter<500;++counter)
    {
        center_point[0]+=move_x;
        center_point[2]+=move_z;
        draw();
    }
}

void Cuboid::rotate(double angle)
{
    rot_mat[0][0]=cos(angle);
    rot_mat[1][1]=cos(angle);
    rot_mat[0][1]=(-1)*sin(angle);
    rot_mat[1][0]=sin(angle);
    draw();
}