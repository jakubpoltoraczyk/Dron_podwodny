#include "bed.h"

void Bed::draw()
{
    using std::vector;
    Vector<double,3> x = (dim[3]-dim[0])*0.1;
    Vector<double,3> y = (dim[1]-dim[0])*0.1;
    Vector<double,3> vec[11][11];
    for(int i=0;i<11;++i)
    {
        for(int j=0;j<11;++j)
        {
            vec[i][j]=dim[0]+x*j+y*i;
        }
    }
    gnuplot->draw_surface(vector<vector<drawNS::Point3D>>
    {
        {vec[0][0],vec[0][1],vec[0][2],vec[0][3],vec[0][4],vec[0][5],vec[0][6],vec[0][7],vec[0][8],vec[0][9],vec[0][10]},
        {vec[1][0],vec[1][1],vec[1][2],vec[1][3],vec[1][4],vec[1][5],vec[1][6],vec[1][7],vec[1][8],vec[1][9],vec[1][10]},
        {vec[2][0],vec[2][1],vec[2][2],vec[2][3],vec[2][4],vec[2][5],vec[2][6],vec[2][7],vec[2][8],vec[2][9],vec[2][10]},
        {vec[3][0],vec[3][1],vec[3][2],vec[3][3],vec[3][4],vec[3][5],vec[3][6],vec[3][7],vec[3][8],vec[3][9],vec[3][10]},
        {vec[4][0],vec[4][1],vec[4][2],vec[4][3],vec[4][4],vec[4][5],vec[4][6],vec[4][7],vec[4][8],vec[4][9],vec[4][10]},
        {vec[5][0],vec[5][1],vec[5][2],vec[5][3],vec[5][4],vec[5][5],vec[5][6],vec[5][7],vec[5][8],vec[5][9],vec[5][10]},
        {vec[6][0],vec[6][1],vec[6][2],vec[6][3],vec[6][4],vec[6][5],vec[6][6],vec[6][7],vec[6][8],vec[6][9],vec[6][10]},
        {vec[7][0],vec[7][1],vec[7][2],vec[7][3],vec[7][4],vec[7][5],vec[7][6],vec[7][7],vec[7][8],vec[7][9],vec[7][10]},
        {vec[8][0],vec[8][1],vec[8][2],vec[8][3],vec[8][4],vec[8][5],vec[8][6],vec[8][7],vec[8][8],vec[8][9],vec[8][10]},
        {vec[9][0],vec[9][1],vec[9][2],vec[9][3],vec[9][4],vec[9][5],vec[9][6],vec[9][7],vec[9][8],vec[9][9],vec[9][10]},
        {vec[10][0],vec[10][1],vec[10][2],vec[10][3],vec[10][4],vec[10][5],vec[10][6],vec[10][7],vec[10][8],vec[10][9],vec[10][10]},
    },color);
}
