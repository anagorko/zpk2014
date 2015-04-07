#include<iostream>
#include<math.h>
#include<assert.h>
using namespace std;

#include "vect.h"

// Metoda zwracaj¹ca wymiar przestrzeni
int Vect::getDimension() const
{
    return dim;
};

// Metoda ustawiaj¹ca wartoœæ wspó³rzêdnej
void Vect::setCoordinate( int n, double w )
{
    assert( n > -1 && n < getDimension() );
    v[n] = w;
};

// Metoda pobieraj¹ca wartoœæ wspó³rzêdnej
double Vect::getCoordinate( int n ) const
{
    assert( n > -1 && n < getDimension() );
    return v[n];
};

// konstruktor kopiuj¹cy
Vect::Vect( const Vect &w )
{
    dim = w.getDimension();
    v = new double[ w.getDimension() ];
    for( int i = 0; i < w.getDimension(); i++ )
        setCoordinate( i, w.getCoordinate( i ) );
};

// Operator podstawienia
Vect& Vect::operator = ( const Vect &w )
{
    assert( w.getDimension() == getDimension() );
    for( int i = 0; i < w.getDimension(); i++)
        setCoordinate( i, w.getCoordinate( i ) );
    return *this;
};

// Operatory dodawania i odejmowania od danego wektora
Vect& Vect::operator+=(const Vect& p)
{
    assert( getDimension() == p.getDimension() );
    for( int i = 0; i < p.getDimension(); i++ )
        setCoordinate( i, getCoordinate( i ) + p.getCoordinate( i ) );
    return *this;
};

Vect& Vect::operator-=(const Vect& p)
{
    assert( getDimension() == p.getDimension() );
    for( int i = 0; i < p.getDimension(); i++ )
        setCoordinate( i, getCoordinate( i ) - p.getCoordinate( i ) );
    return *this;
};

// Iloczyn skalarny
double operator*(const Vect &p1, const Vect &p2)
{
    assert( p1.getDimension() == p2.getDimension() );
    double result = 0;
    for( int i = 0; i < p1.getDimension(); i++ )
        result += p1.getCoordinate( i ) * p2.getCoordinate( i );
    return result;
};

// Metoda obliczaj¹ca normê tego wektora
double Vect::norm() const
{
    return sqrt( *this * *this );
};

// Metoda normalizuj¹ca wektor
void Vect::normalize()
{
    double norma = norm();
    assert( norma != 0 );
    for( int i = 0; i < getDimension(); i++ )
        setCoordinate( i, getCoordinate( i ) / norma );
};

// Dodawanie i odejmowanie wektorów
Vect operator+(const Vect &p1, const Vect &p2)
{
    assert( p1.getDimension() == p2.getDimension() );
    Vect w( p1.getDimension() );
    for( int i = 0; i < w.getDimension(); i++ )
        w.setCoordinate( i, p1.getCoordinate( i ) + p2.getCoordinate( i ) );
    return w;
};

Vect operator-(const Vect &p1, const Vect &p2)
{
    assert( p1.getDimension() == p2.getDimension() );
    Vect w( p1.getDimension() );
    for( int i = 0; i < w.getDimension(); i++ )
        w.setCoordinate( i, p1.getCoordinate( i ) - p2.getCoordinate( i ) );
    return w;
};

// Mno¿enie wektora przez skalar
Vect operator*(const Vect &p, double d)
{
    Vect w( p.getDimension() );
    for( int i = 0; i < w.getDimension(); i++ )
        w.setCoordinate( i, p.getCoordinate( i ) * d );
    return w;
};

Vect operator*(double d, const Vect& p)
{
    return p * d;
};

// Wypisywanie i odczytywanie wektora ze strumieni
ostream& operator<<(ostream &o, const Vect w)
{
    o << "(" << w.getCoordinate( 0 );
    for( int i = 1; i < w.getDimension(); i++ )
        o << "," << w.getCoordinate( i );
    o << ")";
    return o;
};

istream& operator>>(istream &i, Vect &w)
{
    for( int l = 0; l < w.getDimension(); l++ )
        i >> w.v[l];
    return i;
};
