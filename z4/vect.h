#ifndef __VECT_H__
#define __VECT_H__

#include<iostream>
#include<math.h>
using namespace std;

class Vect
{
<<<<<<< HEAD
    int dim;       // wymiar przestrzeni
    double* v;     // tablica wspó³rzêdnych

public:
    // Konstruktor domyœlnie przyjmuje wymiar = 3
=======
    int dim;
    double* v;

public:
>>>>>>> origin/master
    Vect(int _dim = 3)
    {
        dim = _dim;
        v = new double[_dim];
    }

<<<<<<< HEAD
    // Konstruktor inicjalizuj¹cy wspó³rzêdne wektora
=======
>>>>>>> origin/master
    Vect (int _dim, initializer_list<double> _v) : Vect(_dim)
    {
        int i = 0;
        for (const double & d: _v) {
<<<<<<< HEAD
            assert(i + 1 < dim);
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
=======
            v[i++] = d;
        }
    }
    
    ~Vect()
    {
        cout << "destr" << endl;
        
        delete[] v;
    }

    // konstruktor kopiujÄ…cy
    Vect(const Vect &w);
    
    Vect& operator=(const Vect &w);

    void setCoordinate(int,double);
    double getCoordinate(int) const;
    int getDimension() const;
    
    friend istream& operator>>(istream&, Vect&);

    Vect& operator+=(const Vect& p);
    Vect& operator-=(const Vect& p);
    
    double norm() const;
    
    void normalize();
};

Vect operator+(const Vect &p1, const Vect &p2);
Vect operator-(const Vect &p1, const Vect &p2);
double operator*(const Vect &p1, const Vect &p2);

Vect operator*(const Vect &p, double d);
Vect operator*(double d, const Vect& p);

>>>>>>> origin/master
ostream& operator<<(ostream &, const Vect);
istream& operator>>(istream &, Vect&);

#endif
