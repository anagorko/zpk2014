#include "Square.h"

//konstruktory
     Square::Square(Point p, double x)
    {
        a = b = c = d = p;

        b.translate(x,0);
        c.translate(x,x);
        d.translate(0,x);
    }

//tutejsze wersje funkcji virtual z klasy Figure
    double Square::area()
    {
        return a.distanceTo(b) * a.distanceTo(b);
    }

    Figure* Square::scale(double k)
    {
        a.scale(k);
        b.scale(k);
        c.scale(k);
        d.scale(k);
        return this;
    }

   Figure* Square::translate(double dx, double dy)
    {
        a.translate(dx, dy);
        b.translate(dx, dy);
        c.translate(dx, dy);
        d.translate(dx, dy);
        return this;
    }

    Figure*  Square::rotate(double alpha)
    {
        a.rotate(alpha);
        b.rotate(alpha);
        c.rotate(alpha);
        d.rotate(alpha);
        return this;
    }
