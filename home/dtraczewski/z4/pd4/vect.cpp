#include<iostream>
#include<math.h>
#include<assert.h>
using namespace std;

#include "vect.h"

Vect::Vect(const Vect &w){
    dim = w.getDimension();
    v = new double[w.getDimension()];
    for (int i = 0; i < w.getDimension(); ++i) {
        setCoordinate(i, w.getCoordinate(i));
    }
}

void Vect::setCoordinate(int n,double x){
    assert(n >= 0 && n < getDimension());
    v[n] = x;
}

double Vect::getCoordinate(int n) const {
    assert(n >= 0 && n < getDimension());
    return v[n];
}

int Vect::getDimension() const {
    return dim;
}

Vect& Vect::operator=(const Vect &w) {
    assert (getDimension() == w.getDimension());
    for (int i = 0; i < w.getDimension(); ++i) {
        setCoordinate(i, w.getCoordinate(i));
    }
    return *this;
}

Vect& Vect::operator+=(const Vect& p) {
    assert (getDimension() == p.getDimension());
    double x;
    for (int i = 0; i < getDimension(); ++i) {
        x = getCoordinate(i) + p.getCoordinate(i);
        setCoordinate(i, x);
    }
    return *this;
}

Vect& Vect::operator-=(const Vect& p) {
    assert (getDimension() == p.getDimension());
    double x;
    for (int i = 0; i < getDimension(); ++i) {
        x = getCoordinate(i) - p.getCoordinate(i);
        setCoordinate(i, x);
    }
    return *this;
}

double Vect::norm() const {
    return sqrt(*this * *this);
}

void Vect::normalize() {
    assert (norm() != 0);
    double x;
    double norma = norm();
    for (int i = 0; i < getDimension(); ++i) {
        x = getCoordinate(i) / norma;
        setCoordinate(i, x);
    }
}

Vect operator+(const Vect &p1, const Vect &p2) {
    assert (p1.getDimension() == p2.getDimension());
    Vect p(p1.getDimension());
    p = p1;
    p += p2;
    return p;
}

Vect operator-(const Vect &p1, const Vect &p2) {
    assert (p1.getDimension() == p2.getDimension());
    Vect p(p1.getDimension());
    p = p1;
    p -= p2;
    return p;
}

double operator*(const Vect &p1, const Vect &p2) {
    double skalarny = 0;
    assert (p1.getDimension() == p2.getDimension());
    for (int i = 0; i < p1.getDimension(); ++i) {
        skalarny += p1.getCoordinate(i) * p2.getCoordinate(i);
    }
    return skalarny;
}

Vect operator*(const Vect &p, double d) {
    Vect w(p.getDimension());
    w = p;
    for (int i = 0; i < p.getDimension(); ++i) {
        w.setCoordinate(i, p.getCoordinate(i) * d);
    }
    return w;
}

Vect operator*(double d, const Vect& p) {
    return p * d;
}

ostream& operator<<(ostream &o, const Vect w) {
    o << "(" << w.getCoordinate(0);
    for (int i = 1; i < w.getDimension(); ++i) {
        o << "," << w.getCoordinate(i) ;
    }
    o << ")";
    return o;
}
istream& operator>>(istream &i, Vect& w) {
    for (int n = 0; w.getDimension(); ++n) {
        i >> w.v[n];
    }
    return i;
}

