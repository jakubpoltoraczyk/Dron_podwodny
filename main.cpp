#include "cuboid.h"
#include <iostream>
#include <fstream>

int main()
{
    using namespace std;
    double length,high;
    uint id;
    std::ifstream plik;
    plik.open("plik");
    double tab[3]={0.0,0.0,0.0};
    Vector <double,3> vec[8];
    Vector <double,3> center(tab);
    for(int i=0;i<8;++i)
        plik >> vec[i];
    drawNS::APIGnuPlot3D api_gnu(80,-80,80,-80,80,-80,-1);
    Cuboid cub(vec,center,api_gnu);
    id=cub.draw();
    cout << "Podaj 'n': ";
    while(cin.get()!='n');
    cub.move(id,20,30);
    while(cin.get()!='n');
    plik.close();
    return 0;
}