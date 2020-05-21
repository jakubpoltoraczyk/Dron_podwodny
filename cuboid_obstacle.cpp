#include "cuboid_obstacle.h"

bool Cuboid_obstacle::is_collision(const Drone_interface & drone)
{
    double ray = drone.get_ray();
    Vector<double,3> pom[8];
    for(int i=0;i<8;++i)
        pom[i]=center_point+rot_mat*tab[i];
    if(drone.get_center_point()[0]>pom[0][0]-ray&&drone.get_center_point()[0]<pom[1][0]+ray)
        if(drone.get_center_point()[1]>pom[0][1]-ray&&drone.get_center_point()[1]<pom[3][1]+ray)
            if(drone.get_center_point()[2]>pom[0][2]-ray&&drone.get_center_point()[2]<pom[4][2]+ray)
            {
                std::cout << "Ruch wstrzymany - kolizja z pudelkiem\n";
                return true;
            }
    return false;
}