#include<iostream>
#include<math.h>
#include<assert.h>
#include "vect.h"
using namespace std;

// konstruktor kopiujacy
Vect::Vect(const Vect &w){
    dim = w.getDimension();
    v = new double[w.getDimension()];
    for(int i = 0; i < w.getDimension(); i++){
        setCoordinate(i, w.getCoordinate(i));
    }
}

// ustawianie wartosci dla n-tej wspolrzednej
void Vect::setCoordinate(int n, double a){
    assert(n >= 0 && n < getDimension());
    v[n] = a;
}

// pobieranie n-tej wspolrzednej
double Vect::getCoordinate(int n) const {
    assert(n >= 0 && n < getDimension());
    return v[n];
}

// pobieranie wymiaru
int Vect::getDimension() const {
    return dim;
}

// przeciazenie operatora - operator przypisania dla wektora (modyfikuje operand)
Vect& Vect::operator=(const Vect &w) {
    assert (getDimension() == w.getDimension());
    for(int i = 0; i < w.getDimension(); i++) {
        setCoordinate(i, w.getCoordinate(i));
    }
return *this;
}

// przeciazenie operatora - dodawanie wektorow postaci p1 += p2 (modyfikuje operand)
Vect& Vect::operator+=(const Vect& p) {
    assert (getDimension() == p.getDimension());
    for(int i = 0; i < getDimension(); i++) {
        setCoordinate(i, getCoordinate(i) + p.getCoordinate(i));
    }
    return *this;
}

// przeciazenie operatora - odejmowanie wektorow (modyfikuje operand)
Vect& Vect::operator-=(const Vect& p) {
    assert (getDimension() == p.getDimension());
    for(int i = 0; i < getDimension(); i++) {
        setCoordinate(i, getCoordinate(i) - p.getCoordinate(i));
    }
    return *this;
}

// przeciazenie operatora - dodawanie wektorow (zapisanie wyniku w innym wektorze niz operandy)
Vect operator+(const Vect &p1, const Vect &p2) {
    assert (p1.getDimension() == p2.getDimension());
    Vect p(p1);
    p += p2;
    return p;
}

// przeciazenie operatora - odejmowanie wektorow (zapisanie wyniku w innym wektorze niz operandy)
Vect operator-(const Vect &p1, const Vect &p2) {
    assert (p1.getDimension() == p2.getDimension());
    Vect p(p1);
    p -= p2;
    return p;
}

// iloczyn skalarny wektorow - definiowanie operatora poza klasa
double operator*(const Vect &p1, const Vect &p2) {
    assert (p1.getDimension() == p2.getDimension());
    double iloczyn = 0;
    for(int i = 0; i < p1.getDimension(); i++) {
        iloczyn += p1.getCoordinate(i) * p2.getCoordinate(i);
    }
    return iloczyn;
}

// mnozenie wektora przez skalar
Vect operator*(const Vect &p, double d) {
    Vect w(p);
    for(int i = 0; i < w.getDimension(); i++) {
        w.setCoordinate(i, w.getCoordinate(i) * d);
    }
    return w;
}
// oraz skalaru przez wektor
Vect operator*(double d, const Vect& p) {
    return p * d;
}

// Wyznaczanie normy - korzystajac z przeciazenia operatora * do wyznaczania iloczynu skalarnego oraz wskaznik *this
double Vect::norm() const {
    return sqrt(*this * *this);
}

// Normalizacja wektora - modyfikujemy obiekt
void Vect::normalize() {
    assert (norm() != 0);
    double norma = norm();
    for(int i = 0; i < getDimension(); i++) {
        setCoordinate(i, getCoordinate(i) / norma);
    }
}

// przeciazenie operatora strumienia wyjsciowego - wypisywanie wektora
ostream& operator<<(ostream &o, const Vect w) {
    o << "(" << w.getCoordinate(0);
    for(int i = 1; i < w.getDimension(); i++) {
        o << "," << w.getCoordinate(i);
    }
    o << ")";
    return o;
}

// przeciazenie operatora strumienia wejsiowego - wczytywanie wektora
istream& operator>>(istream &i, Vect& w) {
    for(int j = 0; w.getDimension(); j++) {
        i >> w.v[j];
    }
return i;
}
