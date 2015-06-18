#ifndef FIGURE_H
#define FIGURE_H

using namespace std;
#include <iostream>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Figure
{
    virtual ostream& output(ostream&) const = 0;

public:
    virtual double area() = 0;

    virtual Figure* scale(double) = 0;
    virtual Figure* translate(double, double) = 0;
    virtual Figure* rotate(double) = 0;

    friend ostream& operator << (ostream& os, const Figure& f);
};

#endif // FIGURE_H
