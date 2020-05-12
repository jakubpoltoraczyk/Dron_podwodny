#ifndef CUBOID_H
#define CUBOID_H

#include "solid.h"
#include <cmath>

/*!
* \brief Klasa konkretna reprezentujaca prostopadloscian
*
* Klasa umozliwa rysunek, przemieszczenie oraz obrot dowolnego prostopadloscianu
*
*/
class Cuboid: public Solid
{
protected:
    /*!
    * \brief Tablica osmiu punktow reprezntuajacych wierzcholki prostopadloscianu
    */
    Vector<double,3> tab[8];
public:
    /*!
    * \brief Konstruktor
    * \param t - tablica osmiu wektorow 3-wymiarowych (wierzcholkow)
    * \param p - punkt (x,y,z) do przypisania dla srodka bryly
    * \param m - macierz 3-wymiarowa, stanowiaca orientacje bryly
     * \param g - wskaźnik typu klasy abstrakcyjnej drawNS::3DAPI 
     * \param c - przekazanie nowego koloru rysunku
     */
    Cuboid(const Vector<double,3> * t, const Vector<double,3> & p, const Matrix<double,3> & m, const std::string & c, std::shared_ptr<drawNS::Draw3DAPI> g);
    /*!
    * \brief Wirtualny destruktor
    */
    virtual ~Cuboid() {}
    /*!
    * \brief Metoda rysujaca prostopadloscian
    */
    void draw() override;
};

#endif // CUBOID_H