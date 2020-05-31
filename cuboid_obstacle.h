#ifndef CUBOID_OBSTACLE_H
#define CUBOID_OBSTACLE_H

#include "cuboid.h"
#include "obstacle.h"

/*!
* \brief Klasa konkretna reprezentujaca przeszkode w postaci prostopadloscianu
*/

class Cuboid_obstacle: public Cuboid, public Obstacle 
{
public:
    /*!
    * \brief Konstruktor identyczny z konstruktorem dla klasy Cuboid
    * \param t - tablica osmiu wektorow 3-wymiarowych (wierzcholkow)
    * \param p - punkt (x,y,z) do przypisania dla srodka bryly
    * \param m - macierz 3-wymiarowa, stanowiaca orientacje bryly
    * \param g - wskaźnik typu klasy abstrakcyjnej drawNS::3DAPI 
    * \param c - przekazanie nowego koloru rysunku
    */
    Cuboid_obstacle(const Vector<double,3> * t, const Vector<double,3> & p, const Matrix<double,3> & m, const std::string & c, std::shared_ptr<drawNS::Draw3DAPI> g): Cuboid(t,p,m,c,g) {}
    /*!
    * \brief Metoda sprawdzajaca kolizje prostopadloscianu z dronem
    * \param drone - referencja do interfejsu drona
    */
    bool is_collision(const Drone_interface & drone)const override;
    /*!
    * \brief Metoda rysujaca prospadloscienna przeszkode
    */ 
    void draw()override {Cuboid::draw();}
};

#endif // CUBOID_OBSTACLE_H
