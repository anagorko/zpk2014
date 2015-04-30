#include "vect.h"

// konstruktor kopiujący
Vect::Vect(const Vect &w)
{
    dim = w.getDimension();
    v = new double[dim];
    for (int i = 0; i < getDimension(); i++) {
        setCoordinate(i, w.getCoordinate(i));
    }
}

// Operator podstawienia
Vect& Vect::operator=(const Vect &w)
{
    dim = w.getDimension();

    assert(getDimension() == dim);

    if (v == w.v) return *this;
    delete[] v;
    v = new double[dim];
    for (int i = 0; i < getDimension(); i++) {
        setCoordinate(i, w.getCoordinate(i));
    }
    return *this;
}

// Metoda ustawiająca wartość współrzędnej
void Vect::setCoordinate(int n, double c)
{
    assert(n >= 0 && n < getDimension());
    v[n] = c;
}

// Metoda pobierająca wartość współrzędnej
double Vect::getCoordinate(int i) const{
    assert(i >= 0 && i < getDimension());
    return v[i];
}

// Metoda zwracająca wymiar przestrzeni
int Vect::getDimension() const{
    return dim;
}

// Odczytywanie wektora ze strumieni
istream& operator>>(istream& i, Vect& w){
    for(int k=0; k<w.getDimension(); k++){
    i >> w.v[k];
    }
    return i;
}

// Operatory dodawania i odejmowania od danego wektora
Vect& Vect::operator+=(const Vect& p){
    assert(getDimension()==p.getDimension());
    for(int k=0; k<dim; k++){
        setCoordinate(k,getCoordinate(k)+p.getCoordinate(k));
    }
    return *this;
}

Vect& Vect::operator-=(const Vect& p){
    assert(getDimension()==p.getDimension());
    for(int k=0; k<dim; k++){
        setCoordinate(k,getCoordinate(k)-p.getCoordinate(k));
    }
    return *this;
}

// Metoda obliczająca normę tego wektora
double Vect::norm() const{
    double length=0;
    for(int k=0; k<dim; k++){
        length=length+getCoordinate(k)*getCoordinate(k);
    }
    return sqrt(length);
}

// Metoda normalizująca wektor
void Vect::normalize(){
    assert(norm()>0);
    double length=norm();
    for(int k=0; k<dim; k++){
        setCoordinate(k,getCoordinate(k)/length);
    }
}

// Dodawanie i odejmowanie wektorów
Vect operator+(const Vect &p1, const Vect &p2){
    assert(p1.getDimension()==p2.getDimension());
    Vect result(p1);
    for(int k=0; k<result.getDimension(); k++){
    result.setCoordinate(k, result.getCoordinate(k) + p2.getCoordinate(k));
    }
    return result;
}

Vect operator-(const Vect &p1, const Vect &p2){
    assert(p1.getDimension()==p2.getDimension());
    Vect result(p1);
    for(int k=0; k<result.getDimension(); k++){
    result.setCoordinate(k, result.getCoordinate(k) - p2.getCoordinate(k));
    }
    return result;
}

// Iloczyn skalarny
double operator*(const Vect &p1, const Vect &p2){
    assert(p1.getDimension()==p2.getDimension());
    double result=0;
    for(int k=0; k<p1.getDimension(); k++){
        result=result+p1.getCoordinate(k)*p2.getCoordinate(k);
    }
    return result;
}

// Mnożenie wektora przez skalar 1.
Vect operator*(const Vect &p, double d){
    Vect result(p);
    for(int k=0; k<result.getDimension(); k++){
    result.setCoordinate(k, result.getCoordinate(k)*d);
    }
    return result;
}

// Mnożenie wektora przez skalar 2.
Vect operator*(double d, const Vect& p){
    Vect result(p);
    result = p*d;
    return result;
}

// Wypisywanie wektora ze strumieni
ostream& operator<<(ostream &o, const Vect w)
{
    o << "(";
    for(int k=0; k<w.getDimension(); k++){
        o << w.getCoordinate(k);
        if(k<w.getDimension()-1)
            o << ", ";
    }
    o << ")";
    return o;
}
