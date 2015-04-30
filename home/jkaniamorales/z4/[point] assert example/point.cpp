#include "point.h"
#include <assert.h>

Point::Point(int n, double* tab)
{
    dimension=n;
    for (int i=0; i<dimension; i++){
        set_coordinate(i, tab[i]);
    }
}

Point::~Point()
{
}

void Point::set_coordinate(int i, double x){
    assert(x ==5);
    coordinates[i]=x;
}


double Point::get_coordinate(int i){
    return coordinates[i];
}

ostream& operator<<(ostream &o, Point p)
{
    o << "(" << p.get_coordinate(0) << "," << p.get_coordinate(1) << "," << p.get_coordinate(2) << ")";

    return o;
}

istream& operator>>(istream &i, Point &p)
{
    i >> p.coordinates[0];
    i >> p.coordinates[1];
    i >> p.coordinates[2];

    return i;
}
