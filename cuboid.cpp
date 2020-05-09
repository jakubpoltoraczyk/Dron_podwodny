#include "cuboid.h"

Cuboid::Cuboid(const Vector<double,3> * t,const Vector<double,3> & p, const Matrix<double,3> & m, const std::string & c, drawNS::Draw3DAPI * g): Solid(p,m,c,g)
{
    for(int i=0;i<8;++i)
        tab[i]=t[i];
} 

void Cuboid::draw()
{
    using std::vector;
    Cuboid pom(*this);
    for(int i=0;i<8;++i)
        pom.tab[i]=center_point+rot_mat*tab[i];
    id=gnuplot->draw_polyhedron(vector<vector<drawNS::Point3D>>{{pom.tab[0],pom.tab[1],pom.tab[2],pom.tab[3]},{pom.tab[4],pom.tab[5],pom.tab[6],pom.tab[7]}},color);
    gnuplot->redraw();
}