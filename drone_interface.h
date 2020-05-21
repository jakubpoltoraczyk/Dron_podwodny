#ifndef DRONE_INTERFACE_H
#define DRONE_INTERFACE_H

class Drone_interface
{
public:
    virtual ~Drone_interface() {}
    virtual void draw() = 0;
    virtual void move(double angle, double length) = 0;
    virtual void replace(const Vector<double,3> & vec) = 0;
    virtual void rotate(double angle) = 0;
    virtual void change_color(const std::string & c) = 0;
    virtual void erase_object() = 0;
    virtual Vector<double,3> get_center_point()const = 0;
    virtual double get_ray()const = 0;
};

#endif // DRONE_INTERFACE_H