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
    /*! Numer id obecnego rysunku bryly
    * \brief
    */
    double id;
public:
    /*!
     * \brief Konstruktor
     * \param g - wskaźnik typu klasy abstrakcyjnej drawNS::3DAPI 
     * \param c - przekazanie nowego koloru rysunku
     */
    Drawing_interface(const std::string & c, std::shared_ptr<drawNS::Draw3DAPI> g): gnuplot(g), color(c), id(0){}
    /*!
    * \brief Destruktor wirtualny
    */
    virtual ~Drawing_interface() {}
    /*!
    * \brief Metoda czysto abstrakcyjna rysujaca obiekt
    */
    virtual void draw() = 0;
    /*!
    * \brief Metoda usuwajaca obecny rysunek 
    */
    void erase_object() {gnuplot->erase_shape(id);}
    /*!
    * \brief Metoda zmieniajaca kolor rysunku
    * \param c - nowy kolor rysunku
    */
    void change_color(const std::string & c) {erase_object(); color=c;}
};

#endif // DRAWING_INTERFACE