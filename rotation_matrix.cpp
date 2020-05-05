#include "rotation_matrix.h"

Rotation_matrix::Rotation_matrix(const Matrix<double,3> & mat): Matrix<double,3>(mat)
{
    if(mat.det()!=1||!(mat*mat.transposition()==mat.transposition()*mat))
    {
        std::cerr << "Blad: nie jest to macierz obrotu\n";
        exit(1);
    }
}