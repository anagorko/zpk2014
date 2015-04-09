//#include <iostream>
//#include <math.h>
//#include <assert.h>
#include "vect.h"

using namespace std;



    // konstruktor kopiujacy
    Vect::Vect(const Vect &w)
    {
        dim=w.getDimension();
        v= new double[dim];
        for(int i=0; i < dim; i++)
        {
            setCoordinate(i, w.getCoordinate(i));
        }

    };

    // Operator podstawienia
    Vect& Vect::operator=(const Vect &w)
    {
        assert(getDimension()==w.getDimension());
        for (int i = 0; i < w.getDimension(); i++)
            setCoordinate(i, w.getCoordinate(i));

        return *this;
    }

    // Metoda ustawiaj¹ca wartoœæ wspó³rzêdnej
    void Vect::setCoordinate(int n, double w)
    {
        assert(n>=0 && n < getDimension()); //gdy n jest mniejsze od 0 lub wieksze niz wymiar wektora to zatrzymuje program
        v[n]=w;
    }

    // Metoda pobieraj¹ca wartoœæ wspó³rzêdnej
    double Vect::getCoordinate(int n) const
    {
        assert(n>=0 && n < getDimension()); //gdy n jest mniejsze od 0 lub wieksze niz wymiar wektora to zatrzymuje program
        return v[n];
    }

    // Metoda zwracaj¹ca wymiar przestrzeni
    int Vect::getDimension() const
    {
        return dim;
    }

    // Metoda normalizuj¹ca wektor
    void Vect::normalize()
    {
        double norma=norm();
        assert(norma!=0); //gdy dlugosc odcinka rowna 0 to zatrzymuje program
        for(int i=0; i < getDimension(); i++)
            setCoordinate(i, getCoordinate(i)/norma);
    }

    // Metoda obliczaj¹ca normê tego wektora
    double Vect::norm() const
    {
        return sqrt (*this * *this);
    }

    // Iloczyn skalarny, by obliczyc norme wektora
    double operator*(const Vect &p1, const Vect &p2)
    {
        double iskalar=0;
        assert(p1.getDimension() == p2.getDimesion()); //gdy wymiary wektorow sa rozne to zatrzymuje program
        for(int i=0; i < p1.getDimension(); i++)
            iskalar = iskalar + p1.getCoordinate(i) * p2.getCoordinate(i);

        return iskalar;
    }


    // Operatory dodawania i odejmowania od danego wektora
    Vect& Vect::operator+=(const Vect& p)
    {
        assert(getDimension()==p.getDimension());
        for (int i = 0; i < p.getDimension(); i++)
            setCoordinate(i, getCoordinate(i) + p.getCoordinate(i));

        return *this;
    }

    Vect& Vect::operator-=(const Vect& p)
    {
        assert(getDimension()==p.getDimension());
        for (int i = 0; i < p.getDimension(); i++)
            setCoordinate(i, getCoordinate(i) - p.getCoordinate(i));

        return *this;

    }

    // Dodawanie i odejmowanie wektorów
    Vect operator+(const Vect &p1, const Vect &p2)
    {
        assert(p1.getDimension()==p2.getDimension());
        Vect p(p1);
        p+= p2;

        return p;
    }

    Vect operator-(const Vect &p1, const Vect &p2)
    {
        assert(p1.getDimension()==p2.getDimension());
        Vect p(p1);
        p-= p2;

        return p;
    }

    // Mno¿enie wektora przez skalar (mnozenie naprzemienne)
    Vect operator*(const Vect &p, double d)
    {
        Vect wektor(p.getDimension());
        wektor=p;
        for (int i=0; i < p.getDimension(); i++)
            wektor.setCoordinate(i, d * p.getCoordinate(i));

        return wektor;
    }

    Vect operator*(double d, const Vect& p)
    {
        return p * d;
    }

    // Wypisywanie i odczytywanie wektora ze strumieni
    ostream& operator<<(ostream &o, const Vect p)//output
    {
        o << "(";
        for(int i=0; i < p.getDimension(); i++)
            o << "," << p.getCoordinate(i);
        o<< ")";

        return o;
    }

    istream& operator>>(istream &i, Vect &p) //input
    {
        for(int j=0; j < p.getDimension(); j++)
            i >> p.v[j];

        return i;
    }



