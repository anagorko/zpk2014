#ifndef __VECT_H__
#define __VECT_H__

#include<iostream>
#include<math.h>
#include<initializer_list>
#include<assert.h>
using namespace std;


class Vect
{
    int dim;       // wymiar przestrzeni
    double* v;     // tablica wspolrzednych

public:
    // Konstruktor domyslnie przyjmuje wymiar = 3
    Vect(int _dim = 3)
    {
        dim = _dim;
        v = new double[_dim];
    }

    // Konstruktor inicjalizujacy wspolrzedne wektora
    Vect (int _dim, initializer_list<double> _v) : Vect(_dim)
    {
        int i = 0;
        for (const double & d: _v) {
            assert(i < dim);
            v[i++] = d;
        }
    }

    // Destruktor
    ~Vect()
    {
        delete[] v;
    }

    // konstruktor kopiujacy
    Vect(const Vect &w);

    // Operator podstawienia
    Vect& operator=(const Vect &w);

    // Metoda ustawiajaca wartosc wspolrzednej
    void setCoordinate(int,double);

    // Metoda pobierajaca wartosc wspolrzednej
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

// Dodawanie i odejmowanie wektorow
Vect operator+(const Vect &p1, const Vect &p2);
Vect operator-(const Vect &p1, const Vect &p2);

// Iloczyn skalarny
double operator*(const Vect &p1, const Vect &p2);

// Mnozenie wektora przez skalar
Vect operator*(const Vect &p, double d);
Vect operator*(double d, const Vect& p);

// Wypisywanie i odczytywanie wektora ze strumieni
ostream& operator<<(ostream &, const Vect);
istream& operator>>(istream &, Vect&);

#endif
