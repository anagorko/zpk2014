#include<iostream>
#include<math.h>
#include<assert.h>
using namespace std;
#include "vect.h"

// Deklaracja funkcji pomocniczych (tak je zgrupowalem, bo sa potrzebne do wszystkich operacji na wektorach):
    // Wybor wartosci wspolrzednej:
    void Vect :: setCoordinate(int N ,double wspolrzedna){
        v[N - 1] = wspolrzedna;
    }
    // Pobranie wartosci wspolrzednej:
    double Vect :: getCoordinate(int N) const{
        return v[N - 1];
    }
    // Zwrocenie wymiaru wektora - przestrzeni:
    int Vect :: getDimension() const{
        return dim;
    }

//Deklaracja konstruktora kopiujacego:
Vect :: Vect(const Vect & w){
    dim = w.getDimension();
    int dim1 = dim;
    v = new double[dim1];
    for(int k = 0; k < dim1; k++){
        v[k] = w.getCoordinate(k + 1);
    }
}

//Deklaracja operatora podstawienia:
Vect & Vect :: operator = (const Vect & w){
    int dim2 = w.getDimension();
    assert(getDimension() == dim2);
    for(int k = 0; k < dim2; k++){
        setCoordinate(k + 1, w.getCoordinate(k + 1));
    }
    return *this;
}

//Deklaracja operatora dodawania do wektora:
Vect & Vect :: operator += (const Vect & p){
    double robocza = 0;
    int dim3 = p.getDimension();
    assert(getDimension() == dim3);
    for(int k = 0; k < dim3; k++){
        robocza = this -> getCoordinate(k + 1);
        setCoordinate(k + 1, robocza + p.getCoordinate(k + 1));
    }
    return *this;
}

//Deklaracja operatora odejmowania od wektora:
Vect & Vect :: operator -= (const Vect & p){
    double robocza = 0;
    int dim4 = p.getDimension();
    assert(getDimension() == dim4);
    for(int k = 0; k < dim4; k++){
        robocza = getCoordinate(k + 1);
        setCoordinate(k + 1, robocza - p.getCoordinate(k + 1));
    }
    return *this;
}

//Deklaracja metody obliczania normy wektora:
double Vect :: norm() const{
    double norma_wektora = 0;
    double wynik = 0;
    int dim5 = getDimension();
    for(int k = 0; k < dim5; k++){
        norma_wektora += pow(getCoordinate(k + 1),2);
    }
    wynik = sqrt(norma_wektora);
    return(wynik);
}

//Deklaracja normalizacji wektora:
void Vect :: normalize(){
    assert(norm() != 0);
    double robocza = 0;
    double wspol = 0;
    double norma_wektora = norm();
    int dim6 = getDimension();
    for(int k = 0; k < dim6; k++){
        wspol = getCoordinate(k + 1);
        robocza = wspol / norma_wektora ;
        setCoordinate(k + 1,robocza);
    }
}

//Deklaracja operatora dodawania wektorow:
Vect operator + (const Vect & p1, const Vect & p2){
    assert(p1.getDimension() == p2.getDimension());
    Vect w1(p1.getDimension());
    int dim7 = w1.getDimension();
    for(int k = 0; k < dim7; k++){
        w1.setCoordinate(k + 1, p1.getCoordinate(k + 1) + p2.getCoordinate(k + 1));
    }
    return w1;
}

//Deklaracja operatora odejmowania wektorow:
Vect operator - (const Vect & p1, const Vect & p2){
    assert(p1.getDimension() == p2.getDimension());
    Vect w1(p1.getDimension());
    int dim8 = w1.getDimension();
    for(int k = 0; k < dim8; k++){
        w1.setCoordinate(k + 1, p1.getCoordinate(k + 1) - p2.getCoordinate(k + 1));
    }
    return w1;
}

//Deklaracja operatora iloczynu skalarnego wektorow:
double operator * (const Vect & p1, const Vect & p2){
    assert(p1.getDimension() == p2.getDimension());
    double wynik2 = 0;
    int dim9 = p1.getDimension();
    for(int k = 0; k < dim9 ; k++){
        wynik2 += p1.getCoordinate(k + 1) * p2.getCoordinate(k + 1);
    }
    return wynik2;
}

//Deklaracja operatora mnozenia przez stala (skalar) wektora:
Vect operator * (const Vect & p, double d){
    Vect w1(p.getDimension());
    for(int k = 0; k < w1.getDimension(); k++){
        w1.setCoordinate(k + 1 ,p.getCoordinate(k + 1)* d);
    }
    return w1;
}

Vect operator * (double d, const Vect & p){
    Vect w1(p.getDimension());
    w1 = p * d;
    return w1;
}

//Deklaracja operatora odczytu wektora ze strumieni:
ostream & operator << (ostream & o, const Vect p){
    o << "(" << p.getCoordinate(1);
    for(int k = 1; k < p.getDimension(); k++){
        o << " , " << p.getCoordinate(k + 1);
    }
    o << ")";
    return o;
}

istream & operator >> (istream & i, Vect & p){
    for(int k = 0; k < p.getDimension(); k++){
        i >> p.v[k + 1];
    }
    return i;
}

