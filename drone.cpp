#include "drone.h"

void Drone::move(double angle,double length)
{
    double rad = M_PI * angle / 180;
    double divisor = std::abs(100 * length);
    double rotator_angle = 360/divisor;
    double move[3];
    move[0] = cos(rad)*length/divisor;
    move[1] = 0.0;
    move[2] = sin(rad)*length/divisor;
    Vector<double,3> move_vec(move);
    for(int counter=0;counter<divisor;++counter)
    {
        center_point+=rot_mat*move_vec;
        erase_object();
        left_rotator.erase_object();
        right_rotator.erase_object();
        gnuplot->erase_shape(face_id[0]);
        gnuplot->erase_shape(face_id[1]);
        left_rotator.turn(rotator_angle);
        right_rotator.turn(rotator_angle);
        draw();
    }
}

void Drone::draw()
{
    face_id[0]=gnuplot->draw_line(center_point+rot_mat*tab[1],center_point+rot_mat*tab[6],color);
    face_id[1]=gnuplot->draw_line(center_point+rot_mat*tab[2],center_point+rot_mat*tab[5],color);
    left_rotator.draw(center_point+rot_mat*((tab[0]+tab[4])*0.5));
    right_rotator.draw(center_point+rot_mat*((tab[3]+tab[7])*0.5));
    Cuboid::draw();
}

void Drone::rotate(double angle)
{
    double divisor = std::abs(20 * angle);
    double ang = angle/divisor;
    double rotator_angle = 360/divisor;
    for(int i=0;i<divisor;++i)
    {
    left_rotator.erase_object();
    right_rotator.erase_object();
    gnuplot->erase_shape(face_id[0]);
    gnuplot->erase_shape(face_id[1]);
    left_rotator.turn(rotator_angle);
    right_rotator.turn(rotator_angle);
    Cuboid::rotate(ang);
    }
}

void Drone::replace(const Vector<double,3> & v)
{
    gnuplot->erase_shape(face_id[0]);
    gnuplot->erase_shape(face_id[1]);
    left_rotator.erase_object();
    right_rotator.erase_object();
    Cuboid::replace(v);
}

void Drone::change_color(const std::string & c)
{
    erase_object();
    left_rotator.erase_object();
    right_rotator.erase_object();
    gnuplot->erase_shape(face_id[0]);
    gnuplot->erase_shape(face_id[1]);
    color=c;
    draw();
}