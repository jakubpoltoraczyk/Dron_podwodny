#ifndef HEXAGONAL_PRISM
#define HEXAGONAL_PRISM

#include "solid.h"

/*!
* \brief Klasa konkretna reprezentujaca graniastosłup szesciokatny
*
* Klasa umozliwa rysunek, przemieszczenie oraz obrot dowolnego graniastoslupa szesciokatnego
*
*/
class Hexagonal_prism: public Solid
{
protected:
    /*!
    * \brief Tablica osmiu punktow reprezntuajacych wierzcholki prostopadloscianu
    */
    Vector<double,3> tab[12];
public:
    /*!
    * \brief Konstruktor
    * \param t - tablica dwunastu wektorow 3-wymiarowych (wierzcholkow)
    * \param p - punkt (x,y,z) do przypisania dla srodka bryly
    * \param m - macierz 3-wymiarowa, stanowiaca orientacje bryly
     * \param g - wskaźnik typu klasy abstrakcyjnej drawNS::3DAPI 
     * \param c - przekazanie nowego koloru rysunku
     */
    Hexagonal_prism(const Vector<double,3> * t, const Vector<double,3> & p, const Matrix<double,3> & m, const std::string & c, std::shared_ptr<drawNS::Draw3DAPI> g);
    /*!
    * \brief Wirtualny destruktor
    */
    virtual ~Hexagonal_prism() {}
    /*!
    * \brief Metoda rysujaca graniastoslup szesciokatny
    */
    void draw()override;
};

#endif // HEXAGONAL_PRISM