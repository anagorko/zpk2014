#ifndef POINT_H
#define POINT_H

#include<iostream>
#include<math.h>
using namespace std;

class Point
{
    int dimension;
    double* coordinates;

public:
    Point(double default_value=0)
    {
        dimension=3;
        coordinates = new double[3];
        for (int i=0; i<3; i++){
        set_coordinate(i, default_value);
        }
    }

    Point(int, double[]);

    ~Point();

    void set_coordinate(int, double);

    double get_coordinate(int);


    friend istream& operator>>(istream&, Point&);

};


#endif
