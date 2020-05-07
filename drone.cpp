#include "drone.h"

void Drone::move(double angle,double length)
{
    double rad = M_PI * angle / 180;
    double move[3];
    move[2] = sin(rad)*length/1000;
    move[0] = cos(rad)*length/1000;
    move[1] = 0.0;
    Vector<double,3> move_vec(move);
    for(int counter=0;counter<1000;++counter)
    {
        center_point+=rot_mat*move_vec;
        gnuplot->erase_shape(id);
        gnuplot->erase_shape(face_id[0]);
        gnuplot->erase_shape(face_id[1]);
        draw();
    }
}

void Drone::draw()
{
    Cuboid::draw();
    face_id[0]=gnuplot->draw_line(center_point+rot_mat*tab[1],center_point+rot_mat*tab[6],"green");
    face_id[1]=gnuplot->draw_line(center_point+rot_mat*tab[2],center_point+rot_mat*tab[5],"green");
    gnuplot->redraw();
}

void Drone::rotate(double angle)
{
    double ang = angle/1000;
    for(int i=0;i<1000;++i)
    {
    gnuplot->erase_shape(face_id[0]);
    gnuplot->erase_shape(face_id[1]);
    Cuboid::rotate(ang);
    }
}

void Drone::replace(const Vector<double,3> & v)
{
    gnuplot->erase_shape(face_id[0]);
    gnuplot->erase_shape(face_id[1]);
    Cuboid::replace(v);
}