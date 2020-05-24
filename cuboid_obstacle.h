#ifndef CUBOID_OBSTACLE_H
#define CUBOID_OBSTACLE_H

#include "cuboid.h"
#include "obstacle.h"

class Cuboid_obstacle: public Cuboid, public Obstacle 
{
public:
    Cuboid_obstacle(const Vector<double,3> * t, const Vector<double,3> & p, const Matrix<double,3> & m, const std::string & c, std::shared_ptr<drawNS::Draw3DAPI> g): Cuboid(t,p,m,c,g) {}
    bool is_collision(const Drone_interface & drone)const override;
    void draw()override {Cuboid::draw();}
};

#endif // CUBOID_OBSTACLE_H