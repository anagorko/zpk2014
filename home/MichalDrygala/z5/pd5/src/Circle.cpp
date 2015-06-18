#include "Circle.h"

// konstruktor
    Circle::Circle(Point p, double x)
    {
        a = p;
        r = x;
    }

//funkcje
    double Circle::area()
    {
        return 3.14 * r * r;
    }

    Figure* Circle::scale(double k)
    {
        a.scale(k);
        r *= k;
        return this;
    }

    Figure* Circle::translate(double dx, double dy)
    {
        a.translate(dx, dy);
        return this;
    }

    Figure* Circle::rotate(double alpha)
    {
        a.rotate(alpha);
        return this;
    }
