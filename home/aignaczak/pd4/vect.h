#ifndef VECT_H_INCLUDED
#define VECT_H_INCLUDED

#include<iostream>
#include<math.h>
#include<initializer_list>
#include<assert.h>

using namespace std;

class Vect
{
    int dim;       // wymiar przestrzeni
    double* v;     // tablica wsp�rz�dnych

public:
    // Konstruktor domy�lnie przyjmuje wymiar = 3
    Vect(int _dim = 3)
    {
        dim = _dim;
        v = new double[_dim];
    }

    // Konstruktor inicjalizuj�cy wsp�rz�dne wektora
    Vect (int _dim, initializer_list<double> _v) : Vect(_dim)
    {
        int i = 0;
        for (const double & d: _v) {
            assert(i < dim);//assert(i + 1 < dim);
            v[i++] = d;
        }
    }

    // Destruktor
    ~Vect()
    {
        delete[] v;
    }

    // konstruktor kopiuj�cy
    Vect(const Vect &w);

    // Operator podstawienia
    Vect& operator=(const Vect &w);

    // Metoda ustawiaj�ca warto�� wsp�rz�dnej
    void setCoordinate(int n, double wartosc);

    // Metoda pobieraj�ca warto�� wsp�rz�dnej
    double getCoordinate(int n) const;

    // Metoda zwracaj�ca wymiar przestrzeni
    int getDimension() const;

    friend istream& operator>>(istream&, Vect&);

    // Operatory dodawania i odejmowania od danego wektora
    Vect& operator+=(const Vect& p);
    Vect& operator-=(const Vect& p);

    // Metoda obliczaj�ca norm� tego wektora
    double norm() const;

    // Metoda normalizuj�ca wektor
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
ostream& operator<<(ostream &o, const Vect m);
istream& operator>>(istream &is, Vect& m);

#endif

