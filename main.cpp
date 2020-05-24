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
    cout << "\nMenu wyboru opcji drona:" << endl;
    cout << "[-1] - wyjscie z programu" << endl;
    cout << "[0] - dron czerwony" << endl;
    cout << "[1] - dron fioletowy" << endl;
    cout << "[2] - dron zielony" << endl;
    cout << "[d] - usuniecie drona" << endl;
    cout << "[m] - ruch" << endl;
    cout << "[r] - rotacja" << endl;
    cout << "[c] - zmiana koloru" << endl;
}

int main()
{
    using SCENE::Scene;
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
        std::make_shared<Drone>(tab_vec_12,tab_vec_8[0],Vector<double,3>(),mat,"red",api_gnu),
        std::make_shared<Drone>(tab_vec_12,tab_vec_8[0],Vector<double,3>(),mat,"purple",api_gnu),
        std::make_shared<Drone>(tab_vec_12,tab_vec_8[0],Vector<double,3>(),mat,"green",api_gnu)
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
    Scene scene(drone,obs);
    scene.draw();
    int number,length,angle;
    std::string color;
    char option;
    do
    {
        menu();
        std::cout << "Podaj numer drona: ";
        std::cin >> number;
        if(number>-1&&number<3)
        {
            std::cout << "Podaj wybor opcji: ";
            std::cin >> option;
            switch(option)
            {
                case 'm':
                    std::cout << "Podaj kat wznoszenia/opadania oraz dlugosc drogi: ";
                    std::cin >> angle >> length;
                    scene.drone_move(length,angle,number); break;
                case 'r':
                    std::cout << "Podaj kat obrotu: ";
                    std::cin >> angle;
                    scene.drone_rotate(angle,number); break;
                case 'c':
                    std::cout << "Podaj nowy kolor drona: ";
                    std::cin >> color;
                    scene.drone_change_color(color,number); break;
                case 'd':
                    scene.drone_delete(number); break;
                default:
                    std::cout << "Brak opcji o podanym znaku\n";
            }
        }
        else if(number!=-1)
            std::cout << "Brak drona o podanym numerze\n";
    }while(number!=-1);
    file_drone.close();
    return 0;
}