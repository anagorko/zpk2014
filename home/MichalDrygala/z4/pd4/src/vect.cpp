#include "vect.h"

    // konstruktor kopiuj¹cy
Vect::Vect(const Vect &w)
{
    dim = w.getDimension();
    v = new double[dim];
    for(int i = 0; i < dim; i++)
    {
        setCoordinate(i, w.getCoordinate(i));
    }
}

    // Operator podstawienia
Vect& Vect::operator = (const Vect &w)
{
    if(&w == this) return *this;    //sprawdzamy czy podstawiamy to samo pod to samo

    delete []v;                     //usuwamy stare dane

    dim = w.getDimension();
    v = new double[dim];
    for(int i = 0; i < dim; i++)
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
double Vect::getCoordinate(int n) const
{
    assert(n >= 0 && n < getDimension());
    return v[n];
}

    // Metoda zwracaj¹ca wymiar przestrzeni
int Vect::getDimension() const
{
    return dim;
}

    // Operatory dodawania i odejmowania od danego wektora
Vect& Vect::operator += (const Vect&p)
{
    assert(dim == p.getDimension());
    for(int i = 0; i < dim; i++)
    {
        setCoordinate(i, getCoordinate(i) + p.getCoordinate(i));
    }
    return *this;
}

Vect& Vect::operator -= (const Vect& p)
{
    assert(dim == p.getDimension());
    for(int i = 0; i < dim; i++)
    {
        setCoordinate(i, getCoordinate(i) - p.getCoordinate(i));
    }
    return *this;
}

    // Metoda obliczaj¹ca normê tego wektora
double Vect::norm() const
{
    double a = 0.0;
    for(int i = 0; i < dim; i++)
    {
        a += pow( getCoordinate(i), 2);
    }
    return sqrt(a);
}

    // Metoda normalizuj¹ca wektor
void Vect::normalize()
{
  double a = norm();
  assert( a != 0);
  for (int i = 0; i < dim; i++)
  {
      setCoordinate( i, getCoordinate(i) / a );
  }
}

// Dodawanie i odejmowanie wektorów
Vect operator + (const Vect &p1, const Vect &p2)
{
    assert(p1.getDimension() == p2.getDimension());
    Vect rezultat = p1;
    rezultat += p2;
    return rezultat;
}

Vect operator - (const Vect &p1, const Vect &p2)
{
    assert(p1.getDimension() == p2.getDimension());
    Vect rezultat = p1;
    rezultat -= p2;
    return rezultat;
}

// Iloczyn skalarny
double operator * (const Vect &p1, const Vect &p2)
{
    assert(p1.getDimension() == p2.getDimension());
    double a = 0.0;
    for(int i = 0; i < p1.getDimension(); i++)
    {
        a += ( p1.getCoordinate(i) * p2.getCoordinate(i) );
    }
    return a;
}

// Mno¿enie wektora przez skalar
Vect operator * (const Vect &p, double d)
{
    Vect rezultat(p.getDimension());
    for(int i = 0; i < p.getDimension(); i++)
    {
        rezultat.setCoordinate( i, p.getCoordinate(i) * d);
    }
    return rezultat;
}

Vect operator*(double d, const Vect& p)
{
    return p * d;
}

// Wypisywanie i odczytywanie wektora ze strumieni
ostream& operator << (ostream &o, const Vect p)
{
    o << "( ";
    for(int j = 0; j < p.getDimension() - 1; j++)
    {
        o << p.getCoordinate(j) << ", ";
    }
    o << p.getCoordinate( p.getDimension() - 1) << ")";
    return o;
}

istream& operator >> (istream& i, Vect& p)
{
    cout >> "Podaj wymiar wektora: ";
    int a;
    cin >> a;
    Vect re

    for(int j = 0; j < p.dim; j++)
    {
        i >> p.v[j];
    }
    return i;
}
