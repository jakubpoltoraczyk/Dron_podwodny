#include "cuboid.h"
#include "drone.h"
#include <iostream>
#include <fstream>

int main()
{
    using namespace std;
    std::ifstream plik;
    plik.open("plik");
    Vector <double,3> vec[8];
    Matrix <double,3> pom_mat;
    for(int i=0;i<8;++i)
        plik >> vec[i];
    plik >> pom_mat; 
    drawNS::APIGnuPlot3D * api_gnu = new drawNS::APIGnuPlot3D(-100,100,-100,100,-100,100,-1);
    Drone dron01(vec,Vector<double,3>(),pom_mat,api_gnu);
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