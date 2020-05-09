#ifndef SOLID_H
#define SOLID_H

#include "drawing_interface.h"
#include "rotation_matrix.h"

/*!
* \brief Klasa abstrakcyjna reprezentujaca dowolna bryle
*
* Stanowi ona czesciowy interfejs dla klas pochodnych (konkretnych brył)
* Posiada metody wspolne dla kazdej bryly: rotacja oraz zmiana polozenia (bez animacji)

*/

class Solid: public Drawing_interface
{
protected:
    /*!
    * \brief Macierz obrotu (stanowi orientacje bryly)
    */
    Rotation_matrix rot_mat;
    /*!
    * \brief Punkt srodkowy bryly
    */
    Vector<double,3> center_point;
    /*! Numer id obecnego rysunku bryly
    * \brief
    */
    double id;
public:
    /*!
    * \brief Konstruktor
    * \param p - punkt (x,y,z) do przypisania dla srodka bryly
    * \param m - macierz 3-wymiarowa, stanowiaca orientacje bryly
     * \param g - wskaźnik typu klasy abstrakcyjnej drawNS::3DAPI 
     * \param c - przekazanie nowego koloru rysunku
     */
    Solid(const Vector<double,3> & p, const Matrix<double,3> & m, const std::string & c, drawNS::Draw3DAPI * const g): Drawing_interface(c,g), rot_mat(m), center_point(p), id(0){}
    /*!
    * \brief Destruktor wirtualny
    */
    virtual ~Solid() {}
    /*!
    * \brief Metoda czysto abstrakcyjna rysujaca obiekt
    */
    virtual void draw() = 0; 
    /*!
    * \brief Metoda zmiany miejsca bryly (bez animacji)
    * \param vec - punkt (x,y,z) reprezentujacy nowy srodek bryly
    */
    void replace(const Vector<double,3> & vec);
    /*!
    * \brief Metoda zmieniajaca orientacje bryly
    * \param angle - kat zmiany orientacji
    */
    void rotate(double angle);
};

#endif // SOLID_H