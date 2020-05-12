#include "rotation_matrix.h"

Rotation_matrix::Rotation_matrix()
{
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            tab[i][j]=0.0;
    tab[0][0]=1.0;
    tab[1][1]=1.0;
    tab[2][2]=1.0;
}

Rotation_matrix::Rotation_matrix(const Matrix<double,3> & mat): Matrix<double,3>(mat)
{
    if(std::abs(mat.det()-1)>epsilon||!(mat*mat.transposition()==mat.transposition()*mat))
    {
        std::cerr << "Blad: nie jest to macierz obrotu\n";
        exit(1);
    }
}

void Rotation_matrix::rotate_x(double angle)
{   
    Rotation_matrix pom(*this);
    double rad = M_PI * angle / 180;
    pom[1][1]=cos(rad);
    pom[2][2]=cos(rad);
    pom[1][2]=(-1)*sin(rad);
    pom[2][1]=sin(rad);
    *this=*this*pom;
}

void Rotation_matrix::rotate_y(double angle)
{
    Rotation_matrix pom(*this);
    double rad = M_PI * angle / 180;
    pom[0][0]=cos(rad);
    pom[2][2]=cos(rad);
    pom[0][2]=sin(rad);
    pom[2][0]=(-1)*sin(rad);
    *this=*this*pom;
}

void Rotation_matrix::rotate_z(double angle)
{
    Rotation_matrix pom(*this);
    double rad = M_PI * angle / 180;
    pom[0][0]=cos(rad);
    pom[1][1]=cos(rad);
    pom[0][1]=(-1)*sin(rad);
    pom[1][0]=sin(rad);
    *this=*this*pom;
}
