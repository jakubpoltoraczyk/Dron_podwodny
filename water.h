#ifndef WATER_H
#define WATER_H

#include "surface.h"
#include "obstacle.h"

/*!
* \brief Klasa reprezentujaca powierzchnie wody morskiej
*
* Umożliwia ona narysowanie powierzchni wody morskiej w dowolnej przestrzeni R^3
*
*/
class Water: public Surface, public Obstacle
{
protected:
    /*!
    * \brief Punkt reprezentujacy wysokosc morskiej fali (wspolrzedne x oraz y = 0.0) 
    */
    Vector<double,3> wave;
public:
    /*!
    * \brief Konstruktor
    * \param high - wysokosc fali morskiej
    * \param min_x - skrajna odleglosc ujemna plaszczyzny na osi X
    * \param max_x - skrajna odleglosc dodatnia plaszczyzny na osi X
    * \param min_y - skrajna odleglosc ujemna plaszczyzny na osi Y
    * \param max_y - skrajna odleglosc dodatnia plaszczyzny na osi X
    * \param z - wysokosc, na ktorej ma powstac plaszczyzna
    * \param g - wskaźnik typu klasy abstrakcyjnej drawNS::3DAPI 
    * \param c - przekazanie nowego koloru rysunku
    */
    Water(double high, double min_x, double max_x, double min_y, double max_y, double z, const std::string & c, std::shared_ptr<drawNS::Draw3DAPI> g): Surface(min_x,max_x,min_y,max_y,z,c,g)
    {
        double tab[3] = {0.0,0.0,high};
        wave = Vector<double,3>(tab);
    }
    /*!
    * \brief Metoda rysujaca powierzchnie wody morskiej
    */
    void draw()override;
    bool is_collision(const Drone_interface & drone)const override;
};

#endif // WATER_H