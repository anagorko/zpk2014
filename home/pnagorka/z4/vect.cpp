#include "vect.h"
// #include<iostream>
// #include<math.h>
// #include<assert.h>
using namespace std;

// Konstruktor kopiujacy
Vect::Vect(const Vect &w)
{
    dim = w.getDimension();
    v = new double[w.getDimension()];
    for (int i = 0; i < w.getDimension(); i++)
        setCoordinate(i, w.getCoordinate(i));
}

// Operator podstawienia
Vect& Vect::operator=(const Vect &w)
{
    assert(getDimension() == w.getDimension());
    for (int i = 0; i < w.getDimension(); i++)
        setCoordinate(i, w.getCoordinate(i));
    return *this;
}

void Vect::setCoordinate(int n, double d)
{
    assert (n >= 0 && n < getDimension());
    v[n] = d;
}

double Vect::getCoordinate(int n) const
{
    assert (n >= 0 && n < getDimension());
    return v[n];
}

int Vect::getDimension() const
{
    return dim;
}

Vect& Vect::operator+=(const Vect &w)
{
    assert (getDimension() == w.getDimension());
    for (int i = 0; i < getDimension(); i++)
        setCoordinate(i, getCoordinate(i) + w.getCoordinate(i));
    return *this;
}

Vect& Vect::operator-=(const Vect &w)
{
    assert (getDimension() == w.getDimension());
    for (int i = 0; i < getDimension(); i++)
        setCoordinate(i, getCoordinate(i) - w.getCoordinate(i));
    return *this;
}

double Vect::norm() const
{
    return sqrt(*this * *this);
}

void Vect::normalize()
{
    assert (norm() != 0);
    double d = norm();
    for (int i = 0; i < getDimension(); i++)
        setCoordinate(i, getCoordinate(i) / d);
}

Vect operator+(const Vect &w1, const Vect &w2)
{
    assert (w1.getDimension() == w2.getDimension());
    Vect w(w1.getDimension());
    w = w1;
    w += w2;
    return w;
}

Vect operator-(const Vect &w1, const Vect &w2)
{
    assert (w1.getDimension() == w2.getDimension());
    Vect w(w1.getDimension());
    w = w1;
    w -= w2;
    return w;
}

double operator*(const Vect &w1, const Vect &w2)
{
    assert (w1.getDimension() == w2.getDimension());
    double d = 0;
    for (int i = 0; i < w1.getDimension(); i++)
        d = d + w1.getCoordinate(i) * w2.getCoordinate(i);
    return d;
}

Vect operator*(const Vect &w, double d)
{
    Vect r(w.getDimension());
    r = w;
    for (int i = 0; i < w.getDimension(); i++)
        r.setCoordinate(i, d * w.getCoordinate(i));
    return r;
}

Vect operator*(double d, const Vect &w)
{
    return w * d;
}

ostream& operator<<(ostream &ostrm, const Vect w)
{
    ostrm << "(";
    for (int i = 0; i < w.getDimension() - 1; i++)
        ostrm << w.getCoordinate(i) << ",";
    ostrm << w.getCoordinate(w.getDimension() - 1) << ")";
    return ostrm;
}

istream& operator>>(istream &istrm, Vect &w)
{
    for (int i = 0; i < w.getDimension(); i++)
        istrm >> w.v[i];
    return istrm;
}
