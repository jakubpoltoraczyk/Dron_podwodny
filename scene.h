#ifndef SCENE_H
#define SCENE_H

#include "drone.h"
#include "cuboid_obstacle.h"
#include "water.h"
#include "bed.h"

namespace SCENE
{
    using std::vector;
    using std::shared_ptr;
    /*!
    * \brief Klasa konretna reprezentujaca scene kolizyjna z dronem
    *
    * Mozliwe poruszanie sie wybrana iloscia dronow w otoczeniu wybranej ilosci
    * prostopadlosciennych przeszkod, calosc ograniczona od gory powierzchnia wody
    * a od dolu dnem
    */
    class Scene
    {
    private:
        /*!
	* \brief Tablica przechowujaca kolekcje przeszkod
        */
        vector<shared_ptr<Obstacle>> obs;
	/*!
        * \brief Tablica przechowujaca kolekcje dronow
	*/        
	vector<shared_ptr<Drone>> drone;
    public:
	/*!
	* \brief Konstruktor 
	* \param d - kolekcja dronow
	* \param o - kolekcja przeszkod
	*/        
	Scene(const vector<shared_ptr<Drone>> & d,const vector<shared_ptr<Obstacle>> & o): obs(o), drone(d) {}
	/*!
	* Metoda rysujaca wszystkie przeszkody
	*/        
	void draw();
	/*!
	* \brief Metoda poruszajaca wybranym dronem
	* \param length - dlugosc ruchu
	* \param angle - kat wznoszenia\opadania
	* \param n - numer drona		
	*/
        void drone_move(double length, double angle, int n);
	/*!
	* \brief Metoda obracajaca drona
	* \param angle - kat obrotu
	* \param n - numer drona
	*/
        void drone_rotate(double angle, int n);
	/*! 
	* \brief Metoda zmieniajaca kolor drona
	* \param c - nowy kolor
	* \param n - numer drona
	*/
        void drone_change_color(const std::string & c, int n) {drone[n]->change_color(c); drone[n]->draw();}
	/*!
	* \brief Metoda usuwajaca drona
	* \param n - numer drona
	*/        
	void drone_delete(int n) {drone[n]->erase_object();}
    };
}

#endif // SCENE_H
