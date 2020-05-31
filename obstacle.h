#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "drone_interface.h"

/*!
* \brief Klasa abstrakcyjna reprezentujaca przeszkode
*
* Brak konkretnych wspolnych metod, jedynie metody czysto wirtualne
*
*/

class Obstacle
{
public:
    /*!
    * \brief Destruktor wirtualny
    */
    virtual ~Obstacle() {}
    /*!
    * \brief Metoda sprawdzajaca kolizje drona z dana przeszkoda
    */
    virtual bool is_collision(const Drone_interface & drone)const = 0;
    /*!
    * \brief Metoda rysujaca dana przeszkode
    */
    virtual void draw() = 0;
};

#endif //OBSTACLE_H
