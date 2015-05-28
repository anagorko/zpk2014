#include<iostream>
#include<math.h>
#include<assert.h>

#include "vect.h"
using namespace std;


//operator podstawiania
Vect& Vect::operator=(const Vect &w)
{
    dim = w.getDimension();

    if (v == w.v) return *this;

    delete[] v;
    v = new double[dim];

    for (int i = 0; i < getDimension(); i++) {
        setCoordinate(i, w.getCoordinate(i));
    }

    return *this;
}

//konstruktor kopiuj¹cy
Vect::Vect(const Vect &w)
{
    dim = w.getDimension();
    v = new double[dim];

    for (int i = 0; i < getDimension(); i++) {
        setCoordinate(i, w.getCoordinate(i));
    }
}

// Metoda ustawiaj¹ca wartoœæ wspó³rzêdnej
void Vect::setCoordinate(int n,double wartosc){
    assert(n >= 0 && n < getDimension());
    v[n] = wartosc;
}

// Metoda pobieraj¹ca wartoœæ wspó³rzêdnej
double Vect::getCoordinate(int n) const{
    assert(n >= 0 && n < getDimension());
    return v[n];
}

// Metoda zwracaj¹ca wymiar przestrzeni
int Vect::getDimension() const{
    return dim;
}

// Operatory dodawania i odejmowania od danego wektora
Vect& Vect::operator+=(const Vect& p){

    assert(getDimension() == p.getDimension());
    for(int i=0; i<p.getDimension(); i++){
        setCoordinate(i, getCoordinate(i) + p.getCoordinate(i));
    }

    return *this;
}

Vect& Vect::operator-=(const Vect& p){

    assert(getDimension() == p.getDimension());
    for(int i=0; i<p.getDimension(); i++){
        setCoordinate(i, getCoordinate(i) - p.getCoordinate(i));
    }

    return *this;
}

// Metoda obliczaj¹ca normê tego wektora
double Vect::norm() const{
    return sqrt(*this * *this);
}

// Metoda normalizuj¹ca wektor
void Vect::normalize(){
    assert (norm() != 0);
    double k = norm();
    for (int i=0; i<getDimension(); i++){
        setCoordinate(i, getCoordinate(i) / k);
    }
}

// Dodawanie i odejmowanie wektorów
Vect operator+(const Vect &p1, const Vect &p2){
    assert (p1.getDimension() == p2.getDimension());
    Vect p3(p1.getDimension());
    p3 = p1;
    p3 += p2;
    return p3;
}

Vect operator-(const Vect &p1, const Vect &p2){
    assert (p1.getDimension() == p2.getDimension());
    Vect p3(p1.getDimension());
    p3 = p1;
    p3 -= p2;
    return p3;
}

// Iloczyn skalarny
double operator*(const Vect &p1, const Vect &p2){
    assert (p1.getDimension() == p2.getDimension());
    double il=0;
    for(int i=0; i < p1.getDimension(); i++){
        il = il + p1.getCoordinate(i) * p2.getCoordinate(i);
    }
    return il;
}

// Mno¿enie wektora przez skalar
Vect operator*(const Vect &p, double d){
    Vect mn(p);
    mn = p;
    for(int i=0; i<p.getDimension(); i++){
        mn.setCoordinate(i, d * p.getCoordinate(i));
    }
    return mn;
}

Vect operator*(double d, const Vect& p){
    return p * d;
}

// Wypisywanie i odczytywanie wektora ze strumieni
ostream& operator<<(ostream &os, const Vect m){
    os << "(";
    for(int i=0; i<m.getDimension() - 1; i++){
        os << m.getCoordinate(i) << ",";
    }
    os << m.getCoordinate(m.getDimension() - 1);
    os << ")";
    return os;
}

istream& operator>>(istream &is, Vect& m){
    for(int i=0; i<m.getDimension(); i++){
        is >> m.v[i];
    }
    return is;
}
