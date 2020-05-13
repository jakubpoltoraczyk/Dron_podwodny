#include "rotator.h"

void Rotator::draw(const Vector<double,3> & point)
{
    using std::vector;
    Vector <double,3> pom[12];
    Rotation_matrix rot_mat_pom;
    rot_mat_pom.rotate_y(90);
    for(int i=0;i<12;++i)
        pom[i]=point+rot_mat*(turn_mat*(rot_mat_pom*tab[i]));
    id=gnuplot->draw_polyhedron(vector<vector<drawNS::Point3D>>{{pom[0],pom[1],pom[2],pom[3],pom[4],pom[5]},{pom[6],pom[7],pom[8],pom[9],pom[10],pom[11]}},color);
}

void Rotator::rotate(double angle)
{
    erase_object();
    rot_mat.rotate_z(angle);
}

void Rotator::turn(double angle)
{
    erase_object();
    turn_mat.rotate_x(angle);
}