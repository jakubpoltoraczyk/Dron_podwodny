#ifndef ROTATOR_H
#define ROTATOR_H

#include "hexagonal_prism.h"

class Rotator: public Hexagonal_prism
{
protected:
    /*!
    * \brief Macierz obrotu przechowujaca obrotu wirnika wzgledem osi X drona
    */
    Rotation_matrix turn_mat;
public:
    /*!
    * \brief Konstruktor
    * \param t - tablica dwunastu wektorow 3-wymiarowych (wierzcholkow)
    * \param p - punkt (x,y,z) do przypisania dla srodka bryly
    * \param m - macierz 3-wymiarowa, stanowiaca orientacje bryly
     * \param g - wskaźnik typu klasy abstrakcyjnej drawNS::3DAPI 
     * \param c - przekazanie nowego koloru rysunku
     */
    Rotator(const Vector<double,3> * t, const Vector<double,3> & p, const Matrix<double,3> & m, const std::string & c, std::shared_ptr<drawNS::Draw3DAPI> g): Hexagonal_prism(t,p,m,c,g), turn_mat() {}
    /*!
    * \brief Metoda rysujaca wirnik
    */
    void draw(const Vector<double,3> & point);
    /*!
    * \brief Metoda obracaja wirnik wzgledem osi X drona
    * \param angle - kat obrotu
    */
    void turn(double angle);
};

#endif // ROTATOR_H