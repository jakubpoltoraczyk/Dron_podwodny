#include "vector.cpp"
#include "matrix.cpp"

template class Vector <double,3>;

template std::ostream & operator << (std::ostream & o, const Vector<double,3> & v);
template std::istream & operator >> (std::istream & i, Vector<double,3> & v);

template class Matrix <double,3>;

template std::ostream & operator << (std::ostream & o, const Matrix<double,3> & m);
template std::istream & operator >> (std::istream & i, Matrix<double,3> & m);