#ifndef ROTATION_MATRIX
#define ROTATION_MATRIX

#include "matrix.h"

class Rotation_matrix: public Matrix <double,3>
{
public:
    Rotation_matrix(const Matrix<double,3> & mat);
};

#endif //ROTATION_MATRIX