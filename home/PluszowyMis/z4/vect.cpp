#include<iostream>
#include<math.h>
#include<assert.h>

#include "vect.h"

using namespace std;

Vect& Vect::operator=(const Vect &w){
    dim = w.getDimension();

    if(v == w.v)
        return *this;

    delete[] v;
    v = new double[dim];

    for(int i = 0; i < getDimension(); i++){
        setCoordinate(i + 1, w.getCoordinate(i + 1));
    }

    return *this;
}

Vect::Vect(const Vect &w){
    dim = w.getDimension();
    v = new double[dim];

    for(int i = 0; i < getDimension(); i++){
        setCoordinate(i + 1, w.getCoordinate(i + 1));
    }
}

void Vect::setCoordinate(int dimension, double valueCoordinate){
    if(dimension > 0 && dimension <= dim)
        v[dimension - 1] = valueCoordinate;
}

double Vect::getCoordinate(int dimension) const{
    if(dimension > 0 && dimension <= dim)
        return v[dimension - 1];
    else
        return 0;
}

int Vect::getDimension() const{
    return dim;
}

Vect& Vect::operator+=(const Vect& p){
    for(int i = 0; i < this->getDimension() || i < p.getDimension(); i++){
        this->setCoordinate(i + 1, this->getCoordinate(i + 1) + p.getCoordinate(i + 1));
    }
}

Vect& Vect::operator-=(const Vect& p){
    for(int i = 0; i < this->getDimension() || i < p.getDimension(); i++){
        this->setCoordinate(i + 1, this->getCoordinate(i + 1) - p.getCoordinate(i + 1));
    }
}

double Vect::norm() const{
    double result = 0;
    for(int i = 0; i < this->getDimension(); i++){
        result += this->getCoordinate(i + 1) * this->getCoordinate(i + 1);
    }
    return sqrt(result);
}

void Vect::normalize(){
    if(norm() == 0){
        for(int i = 0; i < this->getDimension(); i++){
            this->setCoordinate(i + 1, 0);
        }
    } else{
        double normValue = this->norm();
        for(int i = 0; i < this->getDimension(); i++){
            this->setCoordinate(i + 1, this->getCoordinate(i + 1)/ normValue);
        }
    }
}

//funkcje dodatkowe:
Vect operator+(const Vect &p1, const Vect &p2){
     assert(p1.getDimension() == p2.getDimension());

     Vect result(p1);
     result += p2;

     return result;

}

Vect operator-(const Vect &p1, const Vect &p2){
     assert(p1.getDimension() == p2.getDimension());

     Vect result(p1);
     result -= p2;

     return result;
}

double operator*(const Vect &p1, const Vect &p2){
    assert(p1.getDimension() == p2.getDimension());
    double result = 0;
    for(int i = 0; i < p1.getDimension(); i++){
        result += p1.getCoordinate(i+1)*p2.getCoordinate(i+1);
    }
    return result;
}

Vect operator*(const Vect &p, double d){
    Vect result(p.getDimension());
    result = p;
    for(int i = 0; i < result.getDimension(); i++){
        result.setCoordinate(i + 1, d * result.getCoordinate(i + 1));
    }

    return result;
}

Vect operator*(double d, const Vect& p){
    return p * d;
}

ostream& operator<<(ostream &output, const Vect p){
    output << "(" << p.getCoordinate(1);
    for(int i = 1; i < p.getDimension(); i++){
        output << "," << p.getCoordinate(i + 1);
    }
    output << ")";
    return output;
}

istream& operator>>(istream &input, Vect& p){
    for(int i = 0; i < p.getDimension(); i++){
        input >> p.v[i];
    }
    return input;
}


