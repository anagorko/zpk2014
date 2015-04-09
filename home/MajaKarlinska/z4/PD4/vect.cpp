#include<iostream>
#include<math.h>
#include<assert.h>
using namespace std;

#include "vect.h"

// konstruktor kopiuj¹cy

Vect::Vect(const Vect &w)
    {
    dim = w.getDimension();
    v = new double[w.getDimension()];
    for (int i = 0; i < w.getDimension(); ++i)
        {
        setCoordinate(i, w.getCoordinate(i));
        }
    }

// Operator podstawienia

Vect& Vect::operator=(const Vect &w)
    {
    assert (getDimension() == w.getDimension());
    for (int i = 0; i < w.getDimension(); ++i)
        {
        setCoordinate(i, w.getCoordinate(i));
        }
    return *this;
    }

// Metoda ustawiaj¹ca wartoœæ wspó³rzêdnej
void Vect::setCoordinate(int n, double c)
    {
    assert(n >= 0 && n < getDimension());

    v[n] = c;
    }

// Metoda pobieraj¹ca wartoœæ wspó³rzêdnej
double getCoordinate(int) const;
    {
    assert(n >= 0 && n < getDimension());

    return V[n];
    }

// Metoda zwracaj¹ca wymiar przestrzeni
int Vect::getDimension() const
    {
        return dim;
    }

// Operatory dodawania i odejmowania od danego wektora
Vect& operator+=(const Vect& p);
{
    assert (getDimension() == p.getDimension());
    double x;
    for (int i = 0; i < getDimension(); ++i)
    {
    x = getCoordinate(i) + p.getCoordinate(i);
    setCoordinate(i, x);
    }
    return *this;
}


Vect& operator-=(const Vect& p);
{
    assert (getDimension() == p.getDimension());
    double x;
    for (int i = 0; i < getDimension(); ++i)
    {
    x = getCoordinate(i) - p.getCoordinate(i);
    setCoordinate(i, x);
    }
    return *this;
}


// Metoda obliczaj¹ca normê tego wektora
double Vect::norm() const
    {
        return sqrt(*this * *this);
    }

// Metoda normalizuj¹ca wektor
void Vect::normalize()
    {
        assert(norm()!=0);
        double number;
        double norma=norm();
        for(int i=0;i<getDimension();i++)
            {
            number = getCoordinate(i)/norma;
            setCoordinate(i,number);
            }
    }


// Dodawanie i odejmowanie wektorów
Vect operator+(const Vect &p1, const Vect &p2)
    {
        assert (p1.getDimension()==p2.getDimension());
        Vect p(p1.getDimension());
        p=p1;
        p+=p2;
        return p;
    }

Vect operator-(const Vect &p1, const Vect &p2)
    {
        assert (p1.getDimension()==p2.getDimension());
        Vect p(p1.getDimension());
        p=p1;
        p-=p2;
        return p;
    }

// Iloczyn skalarny

double operator*(const Vect &p1, const Vect &p2)
    {
        assert (p1.getDimension()==p2.getDimension());
        double iloczyn=0;
        for(int i=0;i<p1.getDimension();i++)
            {
            iloczyn+=p1.getCoordinate(i)*p2.getCoordinate(i);
            }
        return iloczyn;
    }

// Mno¿enie wektora przez skalar
Vect operator*(const Vect &p, double d)
    {
        Vect r(p.getDimension());
        r=p;
        for(int i=0;i<p.getDimension();i++)
            {
            r.setCoordinate(i,p.getCoordinate(i)*d);
            }
        return r;
    }

Vect operator*(double d, const Vect& p)
    {
    return p*d;
    }

// Wypisywanie i odczytywanie wektora ze strumieni

ostream& operator<<(ostream &o, const Vect p)
    {
        o<<"("<<p.getCoordinate(0);
        for(int i=1;i<p.getDimension();i++)
            {
            o<<", "<<p.getCoordinate(i);
            }
        o<<")";
        return o;
    }

istream& operator>>(istream &input, Vect &p)
    {
        for(int j=0;j<p.getDimension();j++)
            {
            input >>p.v[j];
            }
        return input;
    }
