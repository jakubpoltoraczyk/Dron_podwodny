#ifndef BED_H
#define BED_H

#include "surface.h"
#include "obstacle.h"

/*!
* \brief Klasa reprezentujaca dno morskie
*
* Umożliwia ona narysowanie dna morskiego w dowolnej przestrzeni R^3
*
*/
class Bed: public Surface, public Obstacle 
{
public:
    /*!
    * \brief Konstruktor
    * \param min_x - skrajna odleglosc ujemna plaszczyzny na osi X
    * \param max_x - skrajna odleglosc dodatnia plaszczyzny na osi X
    * \param min_y - skrajna odleglosc ujemna plaszczyzny na osi Y
    * \param max_y - skrajna odleglosc dodatnia plaszczyzny na osi X
    * \param z - wysokosc, na ktorej ma powstac plaszczyzna
    * \param g - wskaźnik typu klasy abstrakcyjnej drawNS::3DAPI 
    * \param c - przekazanie nowego koloru rysunku
    */
    Bed(double min_x, double max_x, double min_y, double max_y, double z,const std::string & c, std::shared_ptr<drawNS::Draw3DAPI> g): Surface(min_x,max_x,min_y,max_y,z,c,g) {}
    /*!
    * \brief Metoda rysujaca dno morskie
    */
    void draw()override;
    /*!
    * \brief Metoda sprawdzajaca kolizje drona z dnem
    */
    bool is_collision(const Drone_interface & drone)const override;
};

#endif // BED_H
