#include "drone.h"
#include "bed.h"
#include "water.h"
#include <iostream>
#include <fstream>

void menu()
{
    using std::cout;
    using std::endl;
    cout << "\nMenu wyboru opcji drona:" << endl;
    cout << "[e] - wyjscie z programu" << endl;
    cout << "[m] - ruch" << endl;
    cout << "[r] - rotacja" << endl;
    cout << "[c] - zmiana koloru" << endl;
    cout << "[p] - zmiana miejsca (natychmiastowa, bez animacji)" << endl << endl;  
}

int main()
{
    std::ifstream file_drone;
    file_drone.open("file_drone");
    double length,angle;
    std::string color = "blue";
    Vector<double,3> tab_vec_8[8];
    Vector<double,3> tab_vec_12[12];
    Matrix<double,3> mat;
    std::shared_ptr<drawNS::Draw3DAPI> api_gnu(new drawNS::APIGnuPlot3D(-80,80,-80,80,-80,80,-1));
    file_drone >> mat;
    for(int i=0;i<8;++i)
        file_drone >> tab_vec_8[i];
    for(int i=0;i<12;++i)
        file_drone >> tab_vec_12[i];
    Drone drone(tab_vec_12,tab_vec_8,Vector<double,3>(),mat,color,api_gnu);
    Bed bed(-70,70,-70,70,-60,color,api_gnu);
    Water water(10,-70,70,-70,70,60,color,api_gnu);
    bed.draw();
    water.draw();
    drone.draw();
    char option;
    do
    {
        menu();
        std::cout << "Podaj swoj wybor: ";
        std::cin >> option;
        switch(option)
        {
            case 'e':
                std::cout << "Wyjscie z programu" << std::endl; break;
            case 'm':
            std::cout << "Podaj kat spadania/wznoszenia oraz odleglosc: ";
            std::cin >> angle >> length;
            drone.move(angle,length); break;
            case 'r':
            std::cout << "Podaj kat obrotu: ";
            std::cin >> angle;
            drone.rotate(angle); break;
            case 'p':
            std::cout << "Podaj nowy punkt srodkowy (x,y,z): ";
            std::cin >> tab_vec_8[0];
            drone.replace(tab_vec_8[0]); break;
            case 'c':
            std::cout << "Podaj nowy kolor drona: ";
            std::cin >> color;
            drone.change_color(color); break;
            default:
            std::cerr << "Blad wyboru opcji\n";
        }
    }while(option!='e');
    return 0;
}