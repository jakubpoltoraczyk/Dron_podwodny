#include "hexagonal_prism.h"

Hexagonal_prism::Hexagonal_prism(const Vector<double,3> * t, const Vector<double,3> & p, const Matrix<double,3> & m, const std::string & c,std::shared_ptr<drawNS::Draw3DAPI> g): Solid(p,m,c,g)
{
    for(int i=0;i<12;++i)
        tab[i]=t[i];
}

void Hexagonal_prism::draw()
{
    using std::vector;
    Vector <double,3> pom[12];
    for(int i=0;i<12;++i)
        pom[i]=center_point+rot_mat*tab[i];
    id=gnuplot->draw_polyhedron(vector<vector<drawNS::Point3D>>{{pom[0],pom[1],pom[2],pom[3],pom[4],pom[5]},{pom[6],pom[7],pom[8],pom[9],pom[10],pom[11]}},color);
    gnuplot->redraw();
}