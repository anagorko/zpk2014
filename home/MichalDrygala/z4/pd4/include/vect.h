#ifndef __VECT_H__
#define __VECT_H__

#include<iostream>
#include<math.h>
#include <assert.h>

using namespace std;

class Vect
{
    int dim;       // wymiar przestrzeni
    double* v;     // tablica wspó³rzêdnych

public:
    // Konstruktor domyœlnie przyjmuje wymiar = 3
    Vect(int _dim = 3)
    {
        assert(_dim > 0);
        dim = _dim;
        v = new double[_dim];
    }

    // Konstruktor inicjalizuj¹cy wspó³rzêdne wektora
    Vect (int _dim, initializer_list<double> _v) : Vect(_dim)
    {
        assert(_dim > 0);
        int i = 0;
        for (const double & d: _v)
        {
            assert(i < _dim);
            v[i++] = d;
        }
    }

    // Destruktor
    ~Vect()
    {
        delete[] v;
    }

    // konstruktor kopiuj¹cy
    Vect(const Vect &w);

    // Operator podstawienia
    Vect& operator=(const Vect &w);

    // Metoda ustawiaj¹ca wartoœæ wspó³rzêdnej
    void setCoordinate(int,double);

    // Metoda pobieraj¹ca wartoœæ wspó³rzêdnej
    double getCoordinate(int) const;

    // Metoda zwracaj¹ca wymiar przestrzeni
    int getDimension() const;

    friend istream& operator>>(istream&, Vect&);

    // Operatory dodawania i odejmowania od danego wektora
    Vect& operator+=(const Vect& p);
    Vect& operator-=(const Vect& p);

    // Metoda obliczaj¹ca normê tego wektora
    double norm() const;

    // Metoda normalizuj¹ca wektor
    void normalize();
};

// Dodawanie i odejmowanie wektorów
Vect operator+(const Vect &p1, const Vect &p2);
Vect operator-(const Vect &p1, const Vect &p2);

// Iloczyn skalarny
double operator*(const Vect &p1, const Vect &p2);

// Mno¿enie wektora przez skalar
Vect operator*(const Vect &p, double d);
Vect operator*(double d, const Vect& p);

// Wypisywanie i odczytywanie wektora ze strumieni
ostream& operator<<(ostream &, const Vect);
istream& operator>>(istream &, Vect&);

#endif
