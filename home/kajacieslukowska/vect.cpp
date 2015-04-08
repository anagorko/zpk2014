#include "vect.h"

Vect::Vect(const Vect &w){

    dim = w.getDimension();
    v = new double[w.getDimension()];

    for(int i = 1; i <= dim; i++){
    v[i-1]=w.getCoordinate(i);
    }

}

Vect& Vect::operator=(const Vect &w){

    assert(getDimension()==w.getDimension());
    for(int i = 1; i <= w.getDimension(); i++){
        setCoordinate(i,w.getCoordinate(i));
    }

return *this;
}

void Vect::setCoordinate(int n ,double a){
    v[n-1] = a;
}

double Vect::getCoordinate(int n) const{
    return v[n-1];
}

int Vect::getDimension() const{
    return dim;
}

Vect& Vect::operator+=(const Vect& p){

    assert(getDimension()==p.getDimension());
    double t=0;
    for(int i = 1; i <= p.getDimension(); i++){
        t = this->getCoordinate(i);
        setCoordinate(i,t+p.getCoordinate(i));
    }

return *this;
}
Vect& Vect::operator-=(const Vect& p){

    assert(getDimension()==p.getDimension());
    double t=0;
    for(int i = 1; i <= p.getDimension(); i++){
        t = getCoordinate(i);
        setCoordinate(i,t-p.getCoordinate(i));
    }

return *this;
}

double Vect::norm() const{

    double skalar = 0;

    for(int i = 1; i <= getDimension(); i++){
        skalar+= (getCoordinate(i)*getCoordinate(i));
    }

return(sqrt(skalar));
}

void Vect::normalize(){

    assert(norm()!=0);

    double t=0;
    double n = norm();
    for(int i = 1; i <= getDimension(); i++){
        t = getCoordinate(i) / n;
        setCoordinate(i,t);
    }
}

Vect operator+(const Vect &p1, const Vect &p2){

    assert(p1.getDimension()==p2.getDimension());
    Vect k(p1.getDimension());
    for(int i = 1; i <= k.getDimension(); i++){
        k.setCoordinate(i,p1.getCoordinate(i)+p2.getCoordinate(i));
    }

return k;
}

Vect operator-(const Vect &p1, const Vect &p2){

    assert(p1.getDimension()==p2.getDimension());
    Vect k(p1.getDimension());
    for(int i = 1; i <= k.getDimension(); i++){
        k.setCoordinate(i,p1.getCoordinate(i)-p2.getCoordinate(i));
    }

return k;
}

double operator*(const Vect &p1, const Vect &p2){

    assert(p1.getDimension()==p2.getDimension());
    double output = 0;
    for(int i = 1; i <= p1.getDimension(); i++){
        output += p1.getCoordinate(i)*p2.getCoordinate(i);
    }

return output;
}

Vect operator*(const Vect &p, double d){

    Vect k(p.getDimension());
    for(int i = 1; i <= k.getDimension(); i++){
        k.setCoordinate(i,p.getCoordinate(i)*d);
    }

return k;
}

Vect operator*(double d, const Vect& p){

    Vect k(p.getDimension());
    k = p * d;

return k;
}

ostream& operator<<(ostream &o, const Vect p){

    o << "(" << p.getCoordinate(1);
    for(int i = 2; i <= p.getDimension(); i++){
        o << " , " << p.getCoordinate(i);
    }
    o << ")";

return o;
}

istream& operator>>(istream &i, Vect &p){

    for(int j = 1; j <= p.getDimension(); j++){
        i >> p.v[j];
    }

return i;
}
