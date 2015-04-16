#include <iostream>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265359
#endif // M_PI

using namespace std;

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

class Point : public Figure
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
        if( x == 0 && y == 0){
            return this;
        } else{
            double nx = cos(alpha) * x - sin(alpha) * y;
            double ny = sin(alpha) * x + cos(alpha) * y;

            x = nx;
            y = ny;

            return this;
        }
    }

    double distanceTo(Point p)
    {
        double dx = x - p.x;
        double dy = y - p.y;

        return sqrt(dx*dx + dy*dy);
    }

    double getX() const { return x; }
    double getY() const { return y; }
};


class Square : public Figure
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

        return this;
    }

    virtual Figure* translate(double dx, double dy) {
        a.translate(dx, dy);
        b.translate(dx, dy);
        c.translate(dx, dy);
        d.translate(dx, dy);

        return this;
    }

    virtual Figure* rotate(double alpha) {
        a.rotate(alpha);
        b.rotate(alpha);
        c.rotate(alpha);
        d.rotate(alpha);

        return this;
    }
};

class Circle : public Figure{
    Point _centerCirle;
    double _radius;

    virtual ostream& output(ostream& os) const{
        return os << "[" << _centerCirle << ";" << _radius << "]";
    }

public:
    Circle(Point center, double radius){
        this->_centerCirle = center;
        this->_radius = radius;
    }

    Circle() : Circle(Point(), 1){
    }

    virtual double area(){
        return M_PI * _radius * _radius;
    }

    virtual Figure* scale(double scaleValue){
        _radius *= scaleValue;
        return this;
    }

    virtual Figure* translate(double x_translate, double y_translate){
        _centerCirle.translate(x_translate, y_translate);
        return this;
    }

    virtual Figure* rotate(double alphaValue){
        _centerCirle.rotate(alphaValue);
        return this;
    }
};

int main(int argc, char ** argv)
{
    Figure* f = new Square(Point(10.0, 20.0), 30.0);
    Figure* g = new Point(-5.0, 15.0);
    Figure* h = new Circle(Point(0,0), 12);


    cout << *f << " ma pole " << f -> area() << endl;
    cout << *g << " ma pole " << g -> area() << endl;
    cout << *h << " ma pole " << h->area() << endl;

}
