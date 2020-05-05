#include "vector.cpp"

template class Vector <double,3>;

template std::ostream & operator << (std::ostream & o, const Vector<double,3> & v);
template std::istream & operator >> (std::istream & i, Vector<double,3> & v);