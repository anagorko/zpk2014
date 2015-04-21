#include<iostream>
#include<math.h>
using namespace std;



class Point
{
    double x, y, z;

public:
    Point();
    Point(double, double, double);

    ~Point();

    void setX(double);
    void setY(double);
    void setZ(double);

    double getX();
    double getY();
    double getZ();

    friend istream& operator>>(istream&, Point&);
};






Point::Point()
{
    setX(0.0);
    setY(0.0);
    setZ(0.0);
}

Point::Point(double _x, double _y, double _z)
{
    setX(_x);
    setY(_y);
    setZ(_z);
}

Point::~Point()
{
}

void Point::setX(double _x)
{
    x = _x;
}

void Point::setY(double _y)
{
    y = _y;
}

void Point::setZ(double _z)
{
    z = _z;
}


double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}

double Point::getZ()
{
    return z;
}

ostream& operator<<(ostream &o, Point p)
{
    o << "(" << p.getX() << "," << p.getY() << "," << p.getZ() << ")";

    return o;
}

istream& operator>>(istream &i, Point &p)
{
    i >> p.x;
    i >> p.y;
    i >> p.z;

    return i;
}






double odcinek (Point a, Point b)
{

    return sqrt((a.getX()-b.getX())*(a.getX()-b.getX())+(a.getY()-b.getY())*(a.getY()-b.getY())+(a.getZ()-b.getZ())*(a.getZ()-b.getZ()));
}


double area(Point a, Point b, Point c)
{
    double AB = odcinek(a,b);
    double BC = odcinek(a,c);
    double CB = odcinek(c,b);
    double p = (AB+BC+CB)/2;

    return sqrt(p * (p-AB) * (p-BC) * (p-CB));
}

int main()
{
    Point p;
    Point q;
    Point r;

    cout << "Podaj wspolrzedne punktu p: ";
    cin >> p;
    cout << "Podaj wspolrzedne punktu q: ";
    cin >> q;
    cout << "Podaj wspolrzedne punktu r: ";
    cin >> r;
    cout << "Punkty: " << p << " " << q << " " << r << endl;
    cout << "Pole: " << area(p,q,r) << endl;

    return 0;
}
