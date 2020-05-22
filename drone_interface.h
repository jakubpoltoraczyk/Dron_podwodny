#ifndef DRONE_INTERFACE_H
#define DRONE_INTERFACE_H

class Drone_interface
{
public:
    virtual ~Drone_interface() {}
    virtual void move(double angle, double length) = 0;
    virtual Vector<double,3> get_center_point()const = 0;
    virtual double get_ray()const = 0;
    virtual double get_id()const = 0;
};

#endif // DRONE_INTERFACE_H