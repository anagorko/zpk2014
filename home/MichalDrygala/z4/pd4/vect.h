#ifndef __VECT_H__
#define __VECT_H__

#include<iostream>
#include<math.h>
using namespace std;

class Vect
{
    int dim;       // wymiar przestrzeni
    double* v;     // tablica wsp�lrzednych

public:
    // Konstruktor domy�lnie przyjmuje wymiar = 3
    Vect(int);

    // Konstruktor inicjalizujacy wsp�lrzedne wektora
    Vect(int, double);

    // Destruktor
    ~Vect();

    // konstruktor kopiujacy
    Vect(const Vect &);

    // Operator podstawienia
    Vect& operator=(const Vect &);

    // Metoda ustawiajaca wartosc wsp�lrzednej
    void setCoordinate(int,double);

    // Metoda pobierajaca wartosc wsp�lrzednej
    double getCoordinate(int) const;

    // Metoda zwracajaca wymiar przestrzeni
    int getDimension() const;



    friend istream& operator>>(istream&, Vect&);

    // Operatory dodawania i odejmowania od danego wektora
    Vect& operator+=(const Vect& p);
    Vect& operator-=(const Vect& p);

    // Metoda obliczajaca norme tego wektora
    double norm() const;

    // Metoda normalizujaca wektor
    void normalize();
};

// Dodawanie i odejmowanie wektor�w
Vect operator+(const Vect &p1, const Vect &p2);
Vect operator-(const Vect &p1, const Vect &p2);

// Iloczyn skalarny
double operator*(const Vect &p1, const Vect &p2);

// Mno�enie wektora przez skalar
Vect operator*(const Vect &p, double d);
Vect operator*(double d, const Vect& p);

// Wypisywanie i odczytywanie wektora ze strumieni
ostream& operator<<(ostream &, const Vect);
istream& operator>>(istream &, Vect&);

#endif
