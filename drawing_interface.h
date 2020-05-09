#ifndef DRAWING_INTERFACE
#define DRAWING_INTERFACE

#include "Dr3D_gnuplot_api.hh"

/*!
* \brief Klasa reprezentujaca obiekt rysowalny
*
* Klasa abstrakcyjna stanowiaca podstawe dla kazdego obiektu rysowalnego w gnuplocie
*
*/
class Drawing_interface
{
protected:
    /*! 
    * \brief shared_ptr na typ klasy abstrakcyjnej stanowiacej lacze do gnuplota
    */ 
    std::shared_ptr<drawNS::Draw3DAPI> gnuplot;
    /*!
    * \brief zmienna przechowujaca kolor obecnego obiektu
    */ 
    std::string color;
public:
    /*!
     * \brief Konstruktor
     * \param g - wskaźnik typu klasy abstrakcyjnej drawNS::3DAPI 
     * \param c - przekazanie nowego koloru rysunku
     */
    Drawing_interface(const std::string & c, drawNS::Draw3DAPI * const g): gnuplot(g), color(c){}
    /*!
    * \brief Destruktor wirtualny
    */
    virtual ~Drawing_interface() {}
    /*!
    * \brief Metoda czysto abstrakcyjna rysujaca obiekt
    */
    virtual void draw() = 0;
};

#endif // DRAWING_INTERFACE