#ifndef SCENE_H
#define SCENE_H

#include "drone.h"
#include "cuboid_obstacle.h"
#include "water.h"
#include "bed.h"

namespace SCENE
{
    using std::vector;
    using std::shared_ptr;
    class Scene
    {
    private:
        vector<shared_ptr<Obstacle>> obs;
        vector<shared_ptr<Drone>> drone;
    public:
        Scene(const vector<shared_ptr<Drone>> & d,const vector<shared_ptr<Obstacle>> & o): obs(o), drone(d) {}
        void draw();
        void drone_move(double length, double angle, int n);
        void drone_rotate(double angle, int n);
        void drone_change_color(const std::string & c, int n) {drone[n]->change_color(c);}
        void drone_delete(int n) {drone[n]->erase_object();}
    };
}

#endif // SCENE_H