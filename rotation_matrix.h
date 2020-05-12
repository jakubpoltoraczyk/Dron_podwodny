#ifndef ROTATION_MATRIX
#define ROTATION_MATRIX

#include "matrix.h"

class Rotation_matrix: public Matrix<double,3>
{
public:
     Rotation_matrix();
     explicit Rotation_matrix(const Matrix<double,3> & mat);
     Rotation_matrix operator * (const Rotation_matrix & mat)const {return Rotation_matrix((*this).Matrix::operator*(mat));}
     Vector<double,3> operator * (const Vector<double,3> & v)const {return (*this).Matrix::operator*(v);}
     void rotate_x(double angle);
     void rotate_y(double angle);
     void rotate_z(double angle);
};

#endif //ROTATION_MATRIX