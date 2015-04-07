#ifndef __VECT_H__
#define __VECT_H__

#include<iostream>
#include<math.h>
#include <initializer_list>
#include <vector>

using namespace std;

class Vect
{
    int dim;
    double* v;

public:

//Konstruktor
    Vect(int _dim);

//Konstruktor inicjalizujacy wspólrzedne wektora
    Vect (int _dim, initializer_list <double> _v);

//Destruktor
    ~Vect();

//Konstruktor kopiujacy
    Vect(const Vect &w);

//Operator podstawienia
    Vect& operator=(const Vect &w);

//Metoda ustawiajaca wartosc wspólrzêdnej
    void setCoordinate(int,double);
//Metoda pobierajaca wartosc wspólrzêdnej
    double getCoordinate(int) const;
//Metoda zwracajaca wymiar przestrzeni
    int getDimension() const;

    friend istream& operator>>(istream&, Vect&);

//Operatory dodawania i odejmowania od danego wektora
    Vect& operator+=(const Vect& p);
    Vect& operator-=(const Vect& p);

//Metoda obliczajaca norme tego wektora
    double norm() const;

//Metoda normalizujaca wektor
    void normalize();
};

//Dodawanie i odejmowanie wektorów
Vect operator+(const Vect &p1, const Vect &p2);
Vect operator-(const Vect &p1, const Vect &p2);
//Iloczyn skalarny
double operator*(const Vect &p1, const Vect &p2);

//Mno¿enie wektora przez skalar
Vect operator*(const Vect &p, double d);
Vect operator*(double d, const Vect& p);

//Wypisywanie i odczytywanie wektora ze strumieni
ostream& operator<<(ostream &, const Vect);
istream& operator>>(istream &, Vect&);

#endif
