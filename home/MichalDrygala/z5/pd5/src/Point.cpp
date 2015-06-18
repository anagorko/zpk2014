#include "Point.h"

//konstruktory
    Point::Point(double _x, double _y)
    {  x = _x; y = _y;  }

 //tutejsze wersje funkcji virtual z klasy Figure
 Figure* Point::scale(double k)
    {
        x = k * x;
        y = k * y;

        return this;
    };

Figure* Point::translate(double dx, double dy)
    {
        x = x + dx;
        y = y + dy;

        return this;
    }

Figure* Point::rotate(double alpha)
    {
        double nx = cos(alpha) * x - sin(alpha) * y;
        double ny = sin(alpha) * x + cos(alpha) * y;

        x = nx;
        y = ny;

        return this;
    }

// funkcje wlasne klasy Point
    double Point::distanceTo(Point p)
    {
        double dx = x - p.x;
        double dy = y - p.y;

        return sqrt(dx*dx + dy*dy);
    }
