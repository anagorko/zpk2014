#include <iostream>
#include <math.h>
using namespace std;

#include "Point.h"
#include "Square.h"
#include "Circle.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char ** argv)
{
    Figure* f = new Square(Point(10.0, 20.0), 30.0);
    Figure* g = new Point(-5.0, 15.0);
    Figure *h = new Circle(Point(8.0, 12.0), 5.0);

    cout << *f << " ma pole " << f -> area() << endl;
    cout << *g << " ma pole " << g -> area() << endl;
    cout << *h << " ma pole " << h -> area() << endl;
}
