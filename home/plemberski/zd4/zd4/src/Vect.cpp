#include "Vect.h"
#include<assert.h>

 // konstruktor kopiuj¹cy
    Vect::Vect(const Vect &w)
    {
        dim = w.getDimension();
        v = new double[w.getDimension()];

        for (int i=0; i<dim; i++) {
            //assert(i < dim);
            v[i] = w.v[i];
    }
    }

 // Operator podstawienia
    Vect& Vect::operator=(const Vect &wm){
    // 1)
    if(&wm == this) return *this;
    //2)
    delete[] v;
    //3)
           dim = wm.getDimension();
        v = new double[dim];

        for (int i=0; i<dim; i++) {
            assert(i < dim);
            v[i] = wm.v[i];
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
    Vect& Vect::operator+=(const Vect& p)
{
    assert (getDimension() == p.getDimension());

    for (int i=0; i<getDimension(); i++)
        setCoordinate(i, getCoordinate(i)+p.getCoordinate(i));

    return *this;
}


    Vect& Vect::operator-=(const Vect& p)
{
    assert (getDimension() == p.getDimension());

    for (int i=0; i<getDimension(); i++)
        setCoordinate(i, getCoordinate(i)-p.getCoordinate(i));

    return *this;
}

 // Metoda obliczaj¹ca normê tego wektora
    double Vect::norm() const
    {
        double no = 0;
        for (int i=0; i<getDimension(); i++)
        no += getCoordinate(i)*getCoordinate(i);

        return sqrt(no);
    }

   // Metoda normalizuj¹ca wektor
    void Vect::normalize()
    {
      assert (norm() != 0);
double a = norm();
      for (int i=0; i<getDimension(); i++)
        setCoordinate(i, getCoordinate(i)/a);

    }

// Nie z cia³a klasy
Vect operator+(const Vect &p1, const Vect &p2)
{
     assert (p1.getDimension() == p2.getDimension());

     Vect p3(p1.getDimension());
 for (int i=0; i<p1.getDimension(); i++)
        p3.setCoordinate(i, p1.getCoordinate(i) + p2.getCoordinate(i));

        return p3;
}

Vect operator-(const Vect &p1, const Vect &p2)
{
assert(p1.getDimension() == p2.getDimension());

     Vect p4(p1.getDimension());
     p4 = p1;
     p4 -= p2;
     return p4;
}

// Iloczyn skalarny
double operator*(const Vect &p1, const Vect &p2)
{
assert (p1.getDimension() == p2.getDimension());

    double skal=0;

    for (int i=0; i<p1.getDimension(); i++)
        skal += (p1.getCoordinate(i)*p2.getCoordinate(i));

    return skal;
}

// Mno¿enie wektora przez skalar
Vect operator*(const Vect &p, double d)
{
    Vect g(p.getDimension());

    for (int i=0; i<p.getDimension(); i++)
        g.setCoordinate(i,p.getCoordinate(i)*d);

    return g;
}

Vect operator*(double d, const Vect& p)
{
    return p * d;
}

// Wypisywanie i odczytywanie wektora ze strumieni
ostream& operator<<(ostream &o, const Vect k)
{
 o << "(";
    for(int i = 0; i < k.getDimension() - 1; i++){
        o << k.getCoordinate(i) << ",";
    }
    o << k.getCoordinate(k.getDimension() - 1) << ")";
    return o;
}

istream& operator>>(istream &i, Vect& l)
{
  for(int m = 0; m < l.getDimension(); m++){
            i >> l.v[m];
    }

    return i;
}
