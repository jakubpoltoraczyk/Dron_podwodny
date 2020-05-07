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
    double rad = 3.14 * angle / 180;
    double move[3];
    move[2] = sin(rad)*length/1000;
    move[0] = cos(rad)*length/1000;
    move[1] = 0.0;
    Vector<double,3> move_vec(move);
    for(int counter=0;counter<1000;++counter)
    {
        center_point+=rot_mat*move_vec;
        draw();
    }
}

void Cuboid::rotate(double angle)
{
    Rotation_matrix pom(rot_mat);
    double rad = 3.14 * angle / 180;
    pom[0][0]=cos(rad);
    pom[1][1]=cos(rad);
    pom[0][1]=(-1)*sin(rad);
    pom[1][0]=sin(rad);
    rot_mat=Rotation_matrix(rot_mat*pom);
    draw();
}