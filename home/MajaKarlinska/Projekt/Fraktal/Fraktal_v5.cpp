#include <iostream> //cin i cout
#include <math.h> // do pierwiastka
using namespace std;

#include "display.h" //rysowanie na ekranie


class Shape //interfejs Shape, pozwala dzialac na obiektach, pozwala rysowac
{
public:
    virtual void draw(Display) = 0;
};

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

class Point : public Figure, public Shape //punkt dziedziczy z Figure i Shape
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
        return 0; //punkt ma pole 0
    }

    virtual Figure* scale(double k) {
        x = k * x; //skalowanie o k, mnozymy punkt przez k
        y = k * y;

        return this;
    };

    virtual Figure* translate(double dx, double dy) {
        x = x + dx; //przesuniecie dodajemy wektor o ktory mamy przesunac do naszego punktu
        y = y + dy;

        return this;
    }

    virtual Figure* rotate(double alpha) {
        //obrot - wzor z wikipedii
        double nx = cos(alpha) * x - sin(alpha) * y;
        double ny = sin(alpha) * x + cos(alpha) * y;

        x = nx;
        y = ny;

        return this;
    }

    double distanceTo(Point p)
    {
   //wyliczanie odleglosci
        double dx = x - p.x;
        double dy = y - p.y;

        return sqrt(dx*dx + dy*dy);
    }

//metody dostepowe
    double getX() const { return x; }
    double getY() const { return y; }

    void draw(Display d)
    {
        d.drawPoint(x,y);
    }
};

double cXmin = 0.20, cYmin = 0.54;
double cXmax = 0.22, cYmax = 0.55;
double w = cXmax - cXmin;
double h = cYmax - cYmin;
double wMax = cXmax - cXmin;
double hMax = cYmax - cYmin;
double cX = cXmin + w*(cXmax-cXmin)/wMax;
double cY = cYmin + h*(cYmax-cYmin)/hMax;
double _x,_y;
const int n = h*w; //ilosc wskaznikow figur

int main(int argc, char ** argv)
{
    Figure* f[n];
    for (int n=0; n < h*w; n++)
        {
        double xNastepny= _x*_x - _y*_y +cX;
        double yNastepny= 2*_x*_y +cY;
        if (xNastepny*xNastepny + yNastepny*yNastepny > 4)
            break;
        else
            {
            _x= xNastepny;
            _y= yNastepny;
            }
        }
    if (n<255)
        f[n] = new Point(n/255, n/255);

    Display d;
    d.init();

    while (true) {
        d.clear();
        for (int i = 0; i < n; i++) {
            dynamic_cast<Shape*>(f[i]) -> draw(d);
        }
        d.show();

        //usleep(10000);

        /*double m = 1.0;
        for (int i = 0; i < n; i++) {
            f[i] -> rotate(m * 0.02);
            m = -m;
        }*/
    }
}

