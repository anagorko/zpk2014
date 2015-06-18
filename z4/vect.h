#ifndef __VECT_H__
#define __VECT_H__

#include<iostream>
#include<math.h>
using namespace std;

class Vect
{
    int dim;
    double* v;

public:
    Vect(int _dim = 3)
    {
        dim = _dim;
        v = new double[_dim];
    }

    Vect (int _dim, initializer_list<double> _v) : Vect(_dim)
    {
        int i = 0;
        for (const double & d: _v) {
            v[i++] = d;
        }
    }
    
    ~Vect()
    {
        cout << "destr" << endl;
        
        delete[] v;
    }

    // konstruktor kopiujący
    Vect(const Vect &w);
    
    Vect& operator=(const Vect &w);

    void setCoordinate(int,double);
    double getCoordinate(int) const;
    int getDimension() const;
    
    friend istream& operator>>(istream&, Vect&);

    Vect& operator+=(const Vect& p);
    Vect& operator-=(const Vect& p);
    
    double norm() const;
    
    void normalize();
};

Vect operator+(const Vect &p1, const Vect &p2);
Vect operator-(const Vect &p1, const Vect &p2);
double operator*(const Vect &p1, const Vect &p2);

Vect operator*(const Vect &p, double d);
Vect operator*(double d, const Vect& p);

ostream& operator<<(ostream &, const Vect);
istream& operator>>(istream &, Vect&);

#endif
