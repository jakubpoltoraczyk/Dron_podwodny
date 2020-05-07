#ifndef DRONE_H
#define DRONE_H

#include "cuboid.h"

class Drone: public Cuboid
{
protected:
    double face_id[2];
public:
    Drone(const Vector<double,3> * t, const Vector<double,3> & p, const Matrix<double,3> & m, drawNS::APIGnuPlot3D * g): Cuboid(t,p,m,g) {}
    void move(double angle, double length);
    void draw();
    void replace(const Vector<double,3> & vec);
    void rotate(double angle);
};

#endif // DRONE_H