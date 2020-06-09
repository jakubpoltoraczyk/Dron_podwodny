#include "drone.h"
#include "bed.h"
#include "water.h"
#include "cuboid_obstacle.h"
#include "scene.h"
#include <iostream>
#include <fstream>

void menu()
{
    using std::cout;
    using std::endl;
    cout << "\nOption menu:" << endl;
    cout << "[q] - change drone" << endl;
    cout << "[d] - delete drone" << endl;
    cout << "[m] - move" << endl;
    cout << "[r] - rotate" << endl;
    cout << "[c] - change color" << endl;
}

void main_menu(const std::string *c)
{
    using std::cout;
    using std::endl;
    cout << "\nMain menu:" << endl;
    cout << "[-1] - exit" << endl;
    cout << "[0] - " << c[0] << endl;
    cout << "[1] - " << c[1] << endl;
    cout << "[2] - " << c[2]  << endl;
}

int main()
{
  {
    using SCENE::Scene;
    std::string drone_color[3] = {"red","purple","green"};
    std::ifstream file_drone;
    file_drone.open("file_drone");
    Vector<double,3> tab_vec_8[4][8];
    Vector<double,3> tab_vec_12[12];
    Vector <double,3> new_point[5];
    Matrix<double,3> mat;
    std::shared_ptr<drawNS::Draw3DAPI> api_gnu = std::make_shared<drawNS::APIGnuPlot3D>(-120,120,-120,120,-120,120,-1);
    file_drone >> mat;
    for(int i=0;i<8;++i)
        file_drone >> tab_vec_8[0][i];
    for(int i=0;i<12;++i)
        file_drone >> tab_vec_12[i];
    for(int i=1;i<4;++i)
        for(int j=0;j<8;++j)
            file_drone >> tab_vec_8[i][j];
    for(int i=0;i<5;++i)
        file_drone >> new_point[i];
    std::vector<std::shared_ptr<Drone>> drone
    {
        std::make_shared<Drone>(tab_vec_12,tab_vec_8[0],Vector<double,3>(),mat,drone_color[0],api_gnu),
        std::make_shared<Drone>(tab_vec_12,tab_vec_8[0],Vector<double,3>(),mat,drone_color[1],api_gnu),
        std::make_shared<Drone>(tab_vec_12,tab_vec_8[0],Vector<double,3>(),mat,drone_color[2],api_gnu)
    };
    for(int i=1;i<3;++i)
        drone[i]->replace(new_point[i-1]);
    std::vector<std::shared_ptr<Cuboid_obstacle>> cub
    {
        std::make_shared<Cuboid_obstacle>(tab_vec_8[1],Vector<double,3>(),mat,"yellow",api_gnu),
        std::make_shared<Cuboid_obstacle>(tab_vec_8[2],Vector<double,3>(),mat,"yellow",api_gnu),
        std::make_shared<Cuboid_obstacle>(tab_vec_8[3],Vector<double,3>(),mat,"yellow",api_gnu)
    };
    for(int i=0;i<3;++i)
        cub[i]->replace(new_point[i+2]);
    std::vector<std::shared_ptr<Obstacle>> obs
    {
        std::make_shared<Bed>(-110,110,-110,110,-100,"black",api_gnu),
        std::make_shared<Water>(10,-110,110,-110,110,100,"blue",api_gnu),
    };
    for(int i=0;i<3;++i)
        obs.push_back(cub[i]);
    for(int i=0;i<3;++i)
        obs.push_back(drone[i]);
    /******************************************/
    /********KONIEC INICJALIZACJI SCENY********/
    /******************************************/
    Scene scene(drone,obs);
    scene.draw();
    int number,length,angle;
    char option = 'q';
    do
    {
      std::cout << "\nTotal number of vectors: " << Vector<double,3>::get_total_number_of_vec() << std::endl;
      std::cout << "Actual number of vectors: " << Vector<double,3>::get_actual_number_of_vec() << std::endl;
      std::cout << "Total number of solids: " << Solid::get_total_number_of_solids() << std::endl;
      std::cout << "Actual number of solids: " << Solid::get_actual_number_of_solids() << std::endl;
      	if(option=='q')
	{
            main_menu(drone_color);
            std::cout << "Set number of drone: ";
            std::cin >> number;
	}
        if(number>-1&&number<3)
        {
	    menu();
            std::cout << "Set number of option: ";
            std::cin >> option;
            switch(option)
            {
                case 'm':
                    std::cout << "Set angle and length: ";
                    std::cin >> angle >> length;
                    scene.drone_move(length,angle,number); break;
                case 'r':
                    std::cout << "Set angle of rotation: ";
                    std::cin >> angle;
                    scene.drone_rotate(angle,number); break;
                case 'c':
                    std::cout << "Set color of drone: ";
                    std::cin >> drone_color[number];
                    scene.drone_change_color(drone_color[number],number); break;
                case 'd':
                    scene.drone_delete(number); break;
		case 'q':
		    std::cout << "\nReturn to main menu\n"; break;
                default:
                    std::cout << "Unindefined option\n";
            }
        }
        else if(number!=-1)
            std::cout << "Wrong number\n";
    }while(number!=-1);
    file_drone.close();
  }
  std::cout << "\nTotal number of vectors: " << Vector<double,3>::get_total_number_of_vec() << std::endl;
  std::cout << "Actual number of vectors: " << Vector<double,3>::get_actual_number_of_vec() << std::endl;
  std::cout << "Total number of solids: " << Solid::get_total_number_of_solids() << std::endl;
  std::cout << "Actual number of solids: " << Solid::get_actual_number_of_solids() << std::endl;
  std::cout << "Goodbye!" << std::endl;
    return 0;
}
