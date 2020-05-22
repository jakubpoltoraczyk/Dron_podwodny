#include "drone.h"
#include "bed.h"
#include "water.h"
#include "cuboid_obstacle.h"
#include <iostream>
#include <fstream>

void menu()
{
    using std::cout;
    using std::endl;
    cout << "\nMenu wyboru opcji drona:" << endl;
    cout << "[0] - dron czerwony" << endl;
    cout << "[1] - dron fioletowy" << endl;
    cout << "[2] - dron zielony" << endl;
    cout << "[e] - wyjscie z programu" << endl;
    cout << "[d] - usuniecie drona" << endl;
    cout << "[m] - ruch" << endl;
    cout << "[r] - rotacja" << endl;
    cout << "[c] - zmiana koloru" << endl;
}

int main()
{
    std::ifstream file_drone;
    file_drone.open("file_drone");
    double length,angle,divisor;
    std::string color;
    Vector<double,3> tab_vec_8[8];
    Vector<double,3> tab_vec_12[12];
    Vector <double,3> new_point, last_point;
    Matrix<double,3> mat;
    std::shared_ptr<drawNS::Draw3DAPI> api_gnu = std::make_shared<drawNS::APIGnuPlot3D>(-120,120,-120,120,-120,120,-1);
    file_drone >> mat;
    for(int i=0;i<8;++i)
        file_drone >> tab_vec_8[i];
    for(int i=0;i<12;++i)
        file_drone >> tab_vec_12[i];
    Drone drone[3] = 
    {
        Drone(tab_vec_12,tab_vec_8,Vector<double,3>(),mat,"red",api_gnu),
        Drone(tab_vec_12,tab_vec_8,Vector<double,3>(),mat,"purple",api_gnu),
        Drone(tab_vec_12,tab_vec_8,Vector<double,3>(),mat,"green",api_gnu)
    };
    Bed bed(-110,110,-110,110,-100,"black",api_gnu);
    Water water(10,-110,110,-110,110,100,"blue",api_gnu);
    for(int i=0;i<8;++i)
        file_drone >> tab_vec_8[i];
    Cuboid_obstacle cub1(tab_vec_8,Vector<double,3>(),mat,"yellow",api_gnu);
    for(int i=0;i<8;++i)
        file_drone >> tab_vec_8[i];
    Cuboid_obstacle cub2(tab_vec_8,Vector<double,3>(),mat,"yellow",api_gnu);
    for(int i=0;i<8;++i)
        file_drone >> tab_vec_8[i];
    Cuboid_obstacle cub3(tab_vec_8,Vector<double,3>(),mat,"yellow",api_gnu);
    file_drone >> new_point;
    drone[1].replace(new_point);
    file_drone >> new_point;
    drone[2].replace(new_point);
    file_drone >> new_point;
    cub1.replace(new_point);
    file_drone >> new_point;
    cub2.replace(new_point);
    file_drone >> new_point;
    cub3.replace(new_point);
    for(int i=0;i<3;++i)
        drone[i].draw();
    bed.draw();
    water.draw();
    cub1.draw();
    cub2.draw();
    cub3.draw();
    char option;
    int n;
    do
    {
        menu();
        std::cout << "Podaj numer drona: ";
        std::cin >> n;
        if(n>=0&&n<=2)
        {
            std::cout << "Podaj swoj wybor: ";
            std::cin >> option;
            switch(option)
            {
                case 'e':
                std::cout << "Wyjscie z programu" << std::endl; break;
                case 'm':
                std::cout << "Podaj kat spadania/wznoszenia oraz odleglosc: ";
                std::cin >> angle >> length;
                divisor=std::abs(length*20);
                for(int i=0;i<divisor;++i)
                {   
                    drone[n].move(angle,length/divisor);
                    if(i==divisor||water.is_collision(drone[n])||bed.is_collision(drone[n])||cub1.is_collision(drone[n])||cub2.is_collision(drone[n])||cub3.is_collision(drone[n])||
                    drone[n].is_collision(drone[0])||drone[n].is_collision(drone[1])||drone[n].is_collision(drone[2]))
                    {
                        i=divisor;
                        drone[n].move(angle,-length/divisor);
                    }
                    drone[n].draw();
                } 
                break;
                case 'r':
                std::cout << "Podaj kat obrotu: ";
                std::cin >> angle;
                divisor=std::abs(angle*15);
                for(int i=0;i<divisor;++i)
                {
                    drone[n].rotate(angle/divisor);
                    if(cub1.is_collision(drone[n])||cub2.is_collision(drone[n])||cub3.is_collision(drone[n])||
                    drone[n].is_collision(drone[0])||drone[n].is_collision(drone[1])||drone[n].is_collision(drone[2]))
                    {
                        i=divisor;
                        drone[n].rotate(-angle/divisor);
                    }
                    drone[n].draw();
                }
                break;
                case 'c':
                std::cout << "Podaj nowy kolor drona: ";
                std::cin >> color;
                drone[n].change_color(color); break;
                case 'd':
                drone[n].erase_object(); break;
                default:
                std::cerr << "Blad wyboru opcji\n";
            }
        }
        else
        std::cout << "Blad wyboru drona\n";
    }while(option!='e');
    return 0;
}

/*int main()
{
    std::ifstream file_drone;
    file_drone.open("file_drone");
    double length,angle,divisor;
    std::string color;
    Vector<double,3> tab_vec_8[8];
    Vector<double,3> tab_vec_12[12];
    Vector <double,3> new_point, last_point;
    Matrix<double,3> mat;
    std::shared_ptr<drawNS::Draw3DAPI> api_gnu = std::make_shared<drawNS::APIGnuPlot3D>(-120,120,-120,120,-120,120,-1);
    file_drone >> mat;
    for(int i=0;i<8;++i)
        file_drone >> tab_vec_8[i];
    for(int i=0;i<12;++i)
        file_drone >> tab_vec_12[i];
    Drone drone(tab_vec_12,tab_vec_8,Vector<double,3>(),mat,"red",api_gnu);
    std::vector<std::shared_ptr<Obstacle>> obs = 
    {
        std::make_shared<Water>(10,-110,110,-110,110,100,"blue",api_gnu),
        std::make_shared<Bed>(-110,110,-110,110,-100,"black",api_gnu)
    };
    return 0;
}*/