#ifndef SURFACE_H
#define SURFACE_H

#include "drawing_interface.h"
#include "vector.h"

/*!
* \brief Klasa abstrakcyjna reprezentujaca powierzchnie i plaszczyzny
*
* Stanowi ona interfejs dla klas pochodnych (konkretnych plaszczyzn lub powierzchni)
* Brak wspolnych metod dla klas pochodnych
*
*/
class Surface: public Drawing_interface
{
protected:
/*!
* \brief Tablica czterech punktow reprezentujaca skrajne punkty plaszczyzny
*/
    Vector<double,3> dim[4];
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
    Surface(double min_x, double max_x, double min_y, double max_y, double z, const std::string & c, std::shared_ptr<drawNS::Draw3DAPI> g): Drawing_interface(c,g)
    {
        double pom[4][3] = {{min_x,min_y,z},{min_x,max_y,z},{max_x,max_y,z},{max_x,min_y,z}};
        for(int i=0;i<4;++i)
            dim[i]=Vector<double,3>(pom[i]);
    }
    /*!
    * \brief Wirtualny destruktor
    */
    virtual ~Surface() {}
    /*!
    * Wirtualna metoda rysuj plaszczyzne
    */
    virtual void draw() = 0;
};

#endif // SURFACE_H