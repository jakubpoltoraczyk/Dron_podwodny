#ifndef DRONE_INTERFACE_H
#define DRONE_INTERFACE_H

/*!
* \brief Klasa abstrakcyjna sluzaca za interfejs drona
*/
class Drone_interface
{
public:
    /*!
    * \brief Destruktor wirtualny
    */
    virtual ~Drone_interface() {}
    /*!
    * \brief Metoda czysto wirtualna do ruchu dronem
    */
    virtual void move(double angle, double length) = 0;
    /*! 
    * \brief Metoda czysto wirtualna zwracajaca srodek drona
    */
    virtual Vector<double,3> get_center_point()const = 0;
    /*!
    * \brief Metoda czysto wirtualna zwracajaca promien kolizji drona
    */
    virtual double get_ray()const = 0;
    /*! 
    * \brief Metoda czysto wirtualna zwracajaca id drona
    */
    virtual double get_id()const = 0;
};

#endif // DRONE_INTERFACE_H
