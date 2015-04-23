
#include <iostream>
#include "vect.h"
using namespace std;



    // Metoda zwracaj¹ca wymiar przestrzeni
int    Vect::getDimension() const{
    return dim;
}
    // Metoda pobieraj¹ca wartoœæ wspó³rzêdnej
    double Vect::getCoordinate(int a) const{
    assert(a >= 0 && a < getDimension());
    return v[a];
    }

    // Metoda ustawiaj¹ca wartoœæ wspó³rzêdnej
    void Vect::setCoordinate(int n, double c){
    assert(n >= 0 && n < getDimension());
    v[n] = c;
}


    // Operator podstawienia
    Vect& Vect::operator=(const Vect &w){

    dim = w.getDimension();

    if (v == w.v) return *this;

    delete[] v;
    v = new double[dim];

    for (int i = 0; i < getDimension(); i++) {
        setCoordinate(i, w.getCoordinate(i));
        }

    return *this;
    }
    // konstruktor kopiuj¹cy
    Vect::Vect(const Vect &w)
    {
    dim = w.getDimension();
    v = new double[dim];

    for (int i = 0; i < getDimension(); i++) {
        setCoordinate(i, w.getCoordinate(i));
    }
    }

    // Operatory dodawania i odejmowania od danego wektora
    Vect& Vect::operator+=(const Vect& p){

        assert(getDimension() == p.getDimension());

    for(int i=0; i<getDimension(); i++)
setCoordinate(i, p.getCoordinate(i) + getCoordinate(i) );
    return *this;
   }

    Vect& Vect::operator-=(const Vect& p){
        assert(getDimension() == p.getDimension());

    for(int i=0; i<getDimension(); i++)
setCoordinate(i, p.getCoordinate(i) - getCoordinate(i) );
    return *this;
    }

    // Metoda obliczaj¹ca normê tego wektora
    double Vect::norm() const{
        double t=0;
        for(int i=0; i<dim; i++)
          t+= pow(getCoordinate(i),2);
          return sqrt(t);

    }

    // Metoda normalizuj¹ca wektor
    void Vect::normalize(){
        for (int i = 0; i < dim; i++)
            setCoordinate(i, getCoordinate(i)/norm()) ;


    }

    // Dodawanie i odejmowanie wektorów
Vect operator+(const Vect &p1, const Vect &p2){
assert(p1.getDimension()==p2.getDimension());
Vect wektor(p1.getDimension());
for(int i=0; i<p2.getDimension(); i++)
wektor.setCoordinate(i,p1.getCoordinate(i) + p2.getCoordinate(i));
return wektor;

}

Vect operator-(const Vect &p1, const Vect &p2){
assert(p1.getDimension()==p2.getDimension());
Vect wektor(p1.getDimension());
for(int i=0; i<p2.getDimension(); i++)
wektor.setCoordinate(i,p1.getCoordinate(i) - p2.getCoordinate(i));
return wektor;
}

    // Iloczyn skalarny
    double operator*(const Vect &p1, const Vect &p2){
        assert(p1.getDimension()==p2.getDimension());


        double t=0;
        for (int i = 0; i < p1.getDimension(); i++)
         t+=  p1.getCoordinate(i) * p2.getCoordinate(i);
          return t;

    }



    // Mno¿enie wektora przez skalar
    Vect operator*(const Vect &p, double d){
        Vect wek(p.getDimension());
    for( int i = 0; i < p.getDimension(); i++)
      wek.setCoordinate(i, p.getCoordinate(i)*d);
        return wek;
    }

    Vect operator*(double d, const Vect& p){

        Vect wek(p.getDimension());
    for( int i = 0; i < p.getDimension(); i++)
      wek.setCoordinate(i, p.getCoordinate(i)*d);
        return wek;
    }


ostream& operator << (ostream &o, const Vect w){
    o << "(";
    for(int i = 0; i < w.getDimension() - 1; i++){
        o << w.getCoordinate(i) << ",";
    }
    o << w.getCoordinate(w.getDimension() - 1) << ")";
    return o;
}

istream& operator >> (istream &i, Vect&w){
    for(int j = 0; j < w.getDimension(); j++){
            i >> w.v[j];
    }
    return i;
}
