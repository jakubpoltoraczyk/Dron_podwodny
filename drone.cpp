#include "drone.h"

Drone:: Drone(const Vector<double,3> *r, const Vector<double,3> * t, const Vector<double,3> & p, const Matrix<double,3> & m, const std::string & c, std::shared_ptr<drawNS::Draw3DAPI> g):
Cuboid(t,p,m,c,g), left_rotator(r,p,m,c,g), right_rotator(r,p,m,c,g)
{
    ray=(tab[0]-tab[3]).length()*0.5+(r[0]-r[3]).length();
} 

void Drone::move(double angle,double length)
{
    double rad = M_PI * angle / 180;
    double rotator_angle = 0.3*length*360;
    double move[3];
    move[0] = cos(rad)*length;
    move[1] = 0.0;
    move[2] = sin(rad)*length;
    Vector<double,3> move_vec(move);
    center_point+=rot_mat*move_vec;
    Cuboid::erase_object();
    gnuplot->erase_shape(face_id[0]);
    gnuplot->erase_shape(face_id[1]);
    left_rotator.erase_object();
    right_rotator.erase_object();
    left_rotator.turn(rotator_angle);
    right_rotator.turn(rotator_angle);
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
    double rotator_angle = 0.1*angle*360;
    left_rotator.erase_object();
    right_rotator.erase_object();
    gnuplot->erase_shape(face_id[0]);
    gnuplot->erase_shape(face_id[1]);
    left_rotator.turn(rotator_angle);
    right_rotator.turn(rotator_angle);
    left_rotator.rotate(angle);
    right_rotator.rotate(angle);
    Cuboid::rotate(angle);
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
    gnuplot->erase_shape(face_id[0]);
    gnuplot->erase_shape(face_id[1]);
    left_rotator.change_color(c);
    right_rotator.change_color(c);
    Cuboid::change_color(c);
}

void Drone::erase_object()
{
    gnuplot->erase_shape(face_id[0]);
    gnuplot->erase_shape(face_id[1]);
    left_rotator.erase_object();
    right_rotator.erase_object();
    Cuboid::erase_object();
    gnuplot->redraw();
}