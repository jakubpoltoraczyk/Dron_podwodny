#ifndef DRONE_H
#define DRONE_H

#include "cuboid.h"
#include "rotator.h"
#include "drone_interface.h"

/*!
* \brief Klasa konkretna reprezentujaca drona
*
* Dron jest traktowany jako prostopadloscian majacy dodatkowe elementy
*
*/
class Drone: public Drone_interface, Cuboid
{
protected:
    double ray;
    /*! 
    * \brief Tablica id dla "glowy" drona
    */
    double face_id[2];
    Rotator left_rotator, right_rotator;

public:
    /*!
    * \brief Konstruktor
    * \param r - tablica dwunastu wektorow 3-wymiarowych (wierzcholkow)
    * \param t - tablica osmiu wektorow 3-wymiarowych (wierzcholkow)
    * \param p - punkt (x,y,z) do przypisania dla srodka bryly
    * \param m - macierz 3-wymiarowa, stanowiaca orientacje bryly
     * \param g - wskaźnik typu klasy abstrakcyjnej drawNS::3DAPI 
     * \param c - przekazanie nowego koloru rysunku
     */
    Drone(const Vector<double,3> *r, const Vector<double,3> * t, const Vector<double,3> & p, const Matrix<double,3> & m, const std::string & c, std::shared_ptr<drawNS::Draw3DAPI> g);
    /*!
    * \brief Metoda poruszajca dronem (animacja)
    * \param angle - kat wznoszenia\opadania drona
    * \param length - dlugosc drogi, na ktora ma sie przemiescic
    */
    void move(double angle, double length)override;
    /*!
    * \brief Metoda rysujaca drona
    * 
    * Zakrywa ona metode Cuboid::draw(), z ktorej jednak sama w srodku korzysta w celu dorysowania "glowy" drona
    * 
    */
    void draw()override;
    /*!
    * \brief Metoda zmiany miejsca drona (bez animacji)
    * 
    * Zakrywa ona metode Cuboid::replace(...), jednak w srodku z niej korzysta (powod - dodatkowy element "glowa" drona)
    * 
    * \param vec - punkt (x,y,z) reprezentujacy nowy srodek bryly
    */
    void replace(const Vector<double,3> & vec)override;
    /*!
    * \brief Metoda zmieniajaca orientacje drona
    * 
    * Zakrywa ona metode Cuboid::rotate(...), jednak w srodku z niej korzysta (powod - dodatkowy element "glowa" drona)
    * 
    * \param angle - kat zmiany orientacji
    */
    void rotate(double angle)override;
    /*!
    * \brief Metoda zmieniajaca kolor drona
    * \param c - nowy kolor drona
    */
    void change_color(const std::string & c)override;
    void erase_object()override;
    Vector<double,3> get_center_point()const{return center_point;}
    double get_ray()const {return ray;}
};

#endif // DRONE_H