#include "solid.h"

int Solid::actual_number_of_solids = 0;
int Solid::total_number_of_solids = 0;

Solid::Solid(const Solid & s): Drawing_interface(s)
{
    rot_mat = s.rot_mat;
    center_point = s.center_point;
    ++actual_number_of_solids;
    ++total_number_of_solids;
}
