#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "drone_interface.h"

class Obstacle
{
public:
    virtual ~Obstacle() {}
    virtual bool is_collision(const Drone_interface & drone) = 0;
};

#endif //OBSTACLE_H