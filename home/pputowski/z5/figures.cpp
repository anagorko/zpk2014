#include <iostream>
#include <math.h>
using namespace std;

//#include "display.h"

/*
class Shape
{
public:
    virtual void draw(Display) = 0;
};
*/

class Figure
{
    virtual ostream& output(ostream&) const = 0;

public:
    virtual double area() = 0;

    virtual Figure* scale(double) = 0;
    virtual Figure* translate(double, double) = 0;
    virtual Figure* rotate(double) = 0;

    friend ostream& operator<<(ostream& os, const Figure& f);
};

ostream& operator<<(ostream& os, const Figure& f)
{
    return f.output(os);
}

class Point : public Figure//, public Shape
{
    double x, y;

    virtual ostream& output(ostream& os) const {
        return os << "(" <<  x << "," << y << ")";
    }

public:
    Point() : Point(0.0, 0.0) {
    }
    Point(double _x, double _y) {
        x = _x; y = _y;
    }

    virtual double area() {
        return 0;
    }

    virtual Figure* scale(double k) {
        x = k * x;
        y = k * y;

        return this;
    };

    virtual Figure* translate(double dx, double dy) {
        x = x + dx;
        y = y + dy;

        return this;
    }

    virtual Figure* rotate(double alpha) {
        double nx = cos(alpha) * x - sin(alpha) * y;
        double ny = sin(alpha) * x + cos(alpha) * y;

        x = nx;
        y = ny;

        return this;
    }

    double distanceTo(Point p)
    {
        double dx = x - p.x;
        double dy = y - p.y;

        return sqrt(dx*dx + dy*dy);
    }

    double getX() const { return x; }
    double getY() const { return y; }
/*
    void draw(Display d)
    {
        d.drawPoint(x,y);
    }
*/
};


class Square : public Figure//, public Shape
{
    Point a,b,c,d;

    virtual ostream& output(ostream& os) const {
        return os << "[" << a << ";" << b << ";" << c << ";" << d << "]";
    }

public:
    Square(Point p, double x) {
        a = b = c = d = p;

        b.translate(x,0);
        c.translate(x,x);
        d.translate(0,x);
    }

    virtual double area() {
        return a.distanceTo(b) * a.distanceTo(b);
    }

    virtual Figure* scale(double k) {
        a.scale(k);
        b.scale(k);
        c.scale(k);
        d.scale(k);
    }

    virtual Figure* translate(double dx, double dy) {
        a.translate(dx, dy);
        b.translate(dx, dy);
        c.translate(dx, dy);
        d.translate(dx, dy);
    }

    virtual Figure* rotate(double alpha) {
        a.rotate(alpha);
        b.rotate(alpha);
        c.rotate(alpha);
        d.rotate(alpha);

        return this;
    }

/*    void draw(Display disp)
    {
        disp.drawLine(a.getX(),a.getY(),b.getX(),b.getY());
        disp.drawLine(b.getX(),b.getY(),c.getX(),c.getY());
        disp.drawLine(c.getX(),c.getY(),d.getX(),d.getY());
        disp.drawLine(d.getX(),d.getY(),a.getX(),a.getY());
    }
*/
};

class Circle : public Figure
{
    Point s;
    double r;

    virtual ostream& output( ostream& os ) const{
        return os << "[" << s << ", " << r << "]";
    }

public:

    Circle() : Circle( Point(), 1 )
    {
    }

    Circle( Point _s, double _r )
    {
        s = _s;
        r = _r;
    }
    virtual double area()
    {
        double pi = 3.14159265359;
        return pi * r * r;
    }

    virtual Figure* scale( double k )
    {
        r = r * k;
        return this;
    }

    virtual Figure* translate( double dx, double dy )
    {
        s.translate( dx, dy );
        return this;
    }
    virtual Figure* rotate( double alpha )
    {
        return this;
    }
};



int main(int argc, char ** argv)
{
    //Figure *p = new Point( 2.2, 3.3 );
    //Figure *kw = new Square( Point( 1.1, 4.4), 1.1 );
    Figure *h = new Circle( Point( 8, 12 ), 5 ); // zamiast ... wpisz parametry swojego konstruktora opisuj¹ce
                                 // okr¹g o œrodku w punkcie 8.0, 12.0 i promieniu 5.0
    //cout << *p << " ma pole " << p -> area() << endl;
    //cout << *kw << " ma pole " << kw -> area() << endl;
    cout << *h << " ma pole " << h -> area() << endl;
}

/*
const int n = 5;

int main(int argc, char ** argv)
{
    Figure* f[n];

    f[0] = new Square(Point(), 20.0);
    f[0] -> translate(-10.0, -10.0);

    f[1] = new Square(*static_cast<Square*>(f[0]));
    f[1] -> scale(2.0);

    f[2] = new Square(*static_cast<Square*>(f[0]));
    f[2] -> scale(4.0);

    f[3] = new Point(50.0, 50.0);

    f[4] = new Point(70.0, 70.0);

    Display d;
    d.init();

    while (true) {
        d.clear();
        for (int i = 0; i < n; i++) {
            dynamic_cast<Shape*>(f[i]) -> draw(d);
        }
        d.show();

        usleep(10000);

        double m = 1.0;
        for (int i = 0; i < n; i++) {
            f[i] -> rotate(m * 0.02);
            m = -m;
        }
    }
}
*/
