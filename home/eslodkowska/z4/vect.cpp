 #include "vect.h"
using namespace std;

Vect::Vect(const Vect &w){
    dim = w.getDimension();
    v = new double[dim];
    for (int i = 0; i < dim; i++){
        setCoordinate(i, w.getCoordinate(i));
    }
}

void Vect::setCoordinate(int n, double c){
    assert(n >= 0 && n < getDimension());
    v[n] = c;
}

double Vect::getCoordinate(int n) const{
    assert(n >= 0 && n < getDimension());
    return v[n];
}

int Vect::getDimension() const{
    return dim;
}

Vect& Vect::operator=(const Vect &w){
    assert(getDimension() == w.getDimension());
    for(int i = 0; i < w.getDimension(); i++){
        setCoordinate(i, w.getCoordinate(i));
    }
    return *this;
}

Vect& Vect::operator+=(const Vect& w) {
    assert(getDimension() == w.getDimension());
    for (int i = 0; i < w.getDimension(); i++)
        setCoordinate(i, getCoordinate(i) + w.getCoordinate(i));
    return *this;
}

Vect& Vect::operator-=(const Vect& w) {
    assert(getDimension() == w.getDimension());
    for (int i = 0; i < w.getDimension(); i++)
        setCoordinate(i, getCoordinate(i) - w.getCoordinate(i));
    return *this;
}

double Vect::norm() const{
    return sqrt(*this * *this);
}

void Vect::normalize(){
    assert (norm() != 0);
    double n = 1 / norm();
    for (int i = 0; i < getDimension(); i++)
        setCoordinate(i, getCoordinate(i) * n);
}

Vect operator+(const Vect &w1, const Vect &w2){
    assert(w1.getDimension() == w2.getDimension());
    Vect w(w1.getDimension());
    w = w1;
    w += w2;
    return w;
}

Vect operator-(const Vect &w1, const Vect &w2){
    assert(w1.getDimension() == w2.getDimension());
    Vect w(w1.getDimension());
    w = w1;
    w -= w2;
    return w;
}

double operator*(const Vect &w1, const Vect &w2){
    double p = 0;
    assert(w1.getDimension() == w2.getDimension());
    for (int i = 0; i < w1.getDimension(); i++)
        p = p + w1.getCoordinate(i) * w2.getCoordinate(i);
    return p;
}

Vect operator*(const Vect &w, double d){
    Vect s(w.getDimension());
    for (int i = 0; i < w.getDimension(); i++)
        s.setCoordinate(i, d * w.getCoordinate(i));
    return s;
}

Vect operator*(double d, const Vect &w){
    return w * d;
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
