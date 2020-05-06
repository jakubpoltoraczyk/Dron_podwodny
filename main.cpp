#include "cuboid.h"
#include <iostream>
#include <fstream>

int main()
{
    using namespace std;
    double length,angle;
    std::ifstream plik;
    plik.open("plik");
    Vector <double,3> vec[8];
    Matrix <double,3> pom_mat;
    for(int i=0;i<8;++i)
        plik >> vec[i];
    plik >> pom_mat; 
    drawNS::APIGnuPlot3D * api_gnu = new drawNS::APIGnuPlot3D(-100,100,-100,100,-100,100,-1);
    Cuboid cub(vec,Vector<double,3>(),pom_mat,api_gnu);
    cub.draw();
    for(;;)
    {
        cout << "Podaj kat i odleglosc do przemierzenia: ";
        cin >> angle >> length;
        cub.move(angle,length);
        //cout << "Podaj kat zmiany orientacji: ";
        //cin >> angle;
        //cub.rotate(id,angle);
    }
    plik.close();
    return 0;
}