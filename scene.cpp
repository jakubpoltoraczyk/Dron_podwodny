#include "scene.h"

using SCENE::Scene;

void Scene::draw()
{
  for(uint i=0;i<obs.size();++i)
        obs[i]->draw();
}

void Scene::drone_move(double length, double angle, int n)
{
    int divisor=std::abs(length*20);
    for(int i=0;i<divisor;++i)
    {   
        drone[n]->move(angle,length/divisor);
        for(uint j=0;j<obs.size();++j)
            if(obs[j]->is_collision(*drone[n]))
            {
                j=obs.size();
                i=divisor;
                drone[n]->move(angle,-length/divisor);
            }
    drone[n]->draw();
    }
}

void Scene::drone_rotate(double angle, int n)
{
    int divisor=std::abs(angle*15);
    for(int i=0;i<divisor;++i)
    {
    drone[n]->rotate(angle/divisor);
    for(uint j=0;j<obs.size();++j)
        if(obs[j]->is_collision(*drone[n]))
        {
            j=obs.size();
            i=divisor;
            drone[n]->rotate(-angle/divisor);
        }
    drone[n]->draw();
    }
}
