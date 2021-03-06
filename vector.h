#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>
#include "Draw3D_api_interface.hh"

const double epsilon=0.0000000001;

template <typename T, int size>
class Vector // Klasa Vector opisujaca matematyczny wektor
{
private:
    T data[size]; // tablica sluzaca do przechowywania skladowych wektora
    static int actual_number_of_vectors;
    static int total_number_of_vectors;
public:
    Vector(); // konstruktor domyslny
    explicit Vector(const T * tab); // konstruktor przyjmujacy jako argument tablice wartosci typu double
    Vector(const Vector & v); // konstruktor kopiujacy
    ~Vector() {--actual_number_of_vectors;}
    T operator [] (int n) const; // przeciazony operator [] (dostep do skladowych wektora - wersja const)
    T & operator [] (int n); // przeciazony operator [] (dostep do skladowych wektora - wersja bez const)
    Vector operator + (const Vector & v) const; // metoda dodajaca do siebie dwa wektory
    const Vector & operator+=(const Vector & v) {return *this=*this+v;}
    Vector operator - (const Vector & v) const; // metoda odejmujaca od siebie dwa wektory
    T operator * (const Vector & v)const; // metoda mnozaca ze soba dwa wektory
    Vector operator * (const T & n)const; // metoda mnozaca wektor przez wartosc typu double
    bool operator==(const Vector & v)const;
    double length() const {return sqrt(*this**this);} // metoda zwracajaca dlugosc wektora
    operator drawNS::Point3D()const {return drawNS::Point3D(data[0],data[1],data[2]);}
    static int get_total_number_of_vec() {return total_number_of_vectors;}
    static int get_actual_number_of_vec() {return actual_number_of_vectors;}
};

/* Funkcje bezposrednio zwiazane z klasa Vector */
template <typename T, int size>
std::ostream & operator << (std::ostream & o, const Vector<T,size> & v); // przeciazenie operatora << dla klasy Vector
template <typename T, int size>
std::istream & operator >> (std::istream & i, Vector<T,size> & v); // przeciazenie operatora >> dla klasy

#endif //VECTOR_H
