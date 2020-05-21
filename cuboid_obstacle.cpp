#include "cuboid_obstacle.h"

bool Cuboid_obstacle::is_collision(const Drone_interface & drone)
{
    double p = drone.get_ray();
    Vector<double,3> pom[8];
    for(int i=0;i<8;++i)
        pom[i]=center_point+rot_mat*tab[i];
    if(drone.get_center_point()[0]>pom[0][0]-p&&drone.get_center_point()[0]<pom[1][0]+p)
    {
        if(drone.get_center_point()[1]>pom[0][1]-p&&drone.get_center_point()[1]<pom[3][1]+p)
        {
            if(drone.get_center_point()[2]>pom[0][2]-p&&drone.get_center_point()[2]<pom[4][2]+p)
                return true;
        }
    }
    return false;
}