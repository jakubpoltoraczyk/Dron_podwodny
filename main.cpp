#include "cuboid.h"
#include "drone.h"
#include <iostream>
#include <fstream>

int main()
{
    using namespace std;
    std::ifstream plik_drone,plik_boxes;
    plik_drone.open("plik_drone");
    plik_boxes.open("plik_boxes");
    Vector <double,3> vec[8];
    Matrix <double,3> pom_mat;
    for(int i=0;i<8;++i)
        plik_drone >> vec[i];
    plik_drone >> pom_mat; 
    drawNS::APIGnuPlot3D * api_gnu = new drawNS::APIGnuPlot3D(-100,100,-100,100,-100,100,-1);
    Drone dron01(vec,Vector<double,3>(),pom_mat,api_gnu);
    for(int i=0;i<8;++i)
        plik_boxes >> vec[i];
    Cuboid box01(vec,Vector<double,3>(),pom_mat,api_gnu);
    for(int i=0;i<8;++i)
        plik_boxes >> vec[i];
    Cuboid box02(vec,Vector<double,3>(),pom_mat,api_gnu);
    cout << "Podaj punkt srodkowy (x,y,z) pudelka nr 1:\n";
    cin >> vec[0];
    cout << "Podaj punkt srodkowy (x,y,z) pudelka nr 2:\n";
    cin >> vec[1];
    box01.draw();
    box01.replace(vec[0]);
    box02.draw();
    box02.replace(vec[1]);
    dron01.draw();
    for(;;)
    {
        double a,l;
        cout << "Podaj kat i dlugosc ruchu: ";
        cin >> a >> l;
        dron01.move(a,l);
        cout << "Podaj kat obrotu: ";
        cin >> a;
        dron01.rotate(a);
    }
    return 0;
}