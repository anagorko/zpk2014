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

ostream& operator<<(ostream& os, const Figure& f) //operator wypisujacy na strumieniu
//wyjsciowym nasza figurê
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


class Square : public Figure, public Shape //klasa kwadrat
{
    Point a,b,c,d; //4 punkty

    virtual ostream& output(ostream& os) const {
        return os << "[" << a << ";" << b << ";" << c << ";" << d << "]";
    }

public:
    Square(Point p, double x) {//dostajemy jako argument punkt p, i wszystkie 4
        //wierzcho³ki podstawia jako punkt p, po kolei. najpierw pod p podstawiamy
        //d, pozniej c
        a = b = c = d = p;

        b.translate(x,0); //przesuwamy wierzcholek b o x w prawo
        c.translate(x,x); //przesuwamy wierzcholek c o x w gore i x w prawo
        d.translate(0,x); //przesuwamy wierzcholek d o y w gore
    //konstruktor tworzy boki rownolegle do osi

    }

    virtual double area() {
        //virtual - aby latwiej bylo rozpoznac ze metoda jest z innej klasy
        //mowimy tyle ze chcemy stosowac polimorfizm wzgledem tej metody
        //przed ktorej nazwa mamy virtual
        return a.distanceTo(b) * a.distanceTo(b); //a^2 - dlugosc boku do kwadratu
        // to pole kwadratu, a.dstanceTo(b) - dlugosc boku AB
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

    void draw(Display disp)
    {
        disp.drawLine(a.getX(),a.getY(),b.getX(),b.getY());
        disp.drawLine(b.getX(),b.getY(),c.getX(),c.getY());
        disp.drawLine(c.getX(),c.getY(),d.getX(),d.getY());
        disp.drawLine(d.getX(),d.getY(),a.getX(),a.getY());
    }

};

const int n = 5; //ilosc wskaznikow figur

int main(int argc, char ** argv)
{
    Figure* f[n]; //deklaruje tablice 5 elementow - figur
    //dlaczego to sie kompiluje skoro nie istnieja obiekty z klasy Figure?
    //* jest istotne, *oznacza ze cos jest wskaznikiem do obiektu z klasy
    //Figure, mowi nam to o adresie danego obiektu, ktory moze byc zarowno
    //w klasie jak i kazdej podklasie.
    // (gdyby bylo Figure f[n], to byloby zle i by sie nie skompilowalo)

    f[0] = new Square(Point(), 20.0); //f0 - kwadrat, tworzymy nowy kwadrat
    //jako pierwszy argument bierze Point (lewy gorny rog) - czyli (0;0), bo Point
    //w konstruktorze wczesniej przyjmuje 0;0 Jesli nie dodamy kolejnej linii to
    //kwadrat bedzie krecil sie wokol punktu 0;0
    f[0] -> translate(-10.0, -10.0); //strzalka -> oznazca to ze jest to wskaznik
    //do czegos z klasy Figure, wywola to metode translate z obiektu na ktory
    //wskazuje, czyli f[0] z klasy Figure. Ale klasa figure ma tylko metody abstrakcyjne
    //Tutaj wchodzi polimorfizm - jesli cos mowi ze jest wskaznikiem do klasu A
    //jesli mamy wskaznik do klasy B, a klasa B dziedzi czy z A, to
    //wskaznik z klasy B poradzi sobie z tym co wskaznik z klasy A (???)
    //mozemy stworzyc tak, pomimo, ze obiekty Figur nie istnieja, poniewaz
    //korzystamy z opdklasy Square, a tam juz istnieja obiekty i mozemy je wywolac
    //metoda transolate jest zadefiniowana w klasie Square, ktora jest podklasa Figure
    //wiec mozemy z niego korzystac

    //wywolujemy metody tak samo i do kwadratow i do punktow, ale
    //kiedy wywolujemy metode dla kwadratow wowczas uzywana jest metoda z klasy Square
    // a kiedy metode dla punktot, to metoda z klasy Point

    f[1] = new Square(*static_cast<Square*>(f[0])); //f1 - kwadrat
    //*statis cast to wywolanie konstruktora kopiujacego
    //mozna tez tak, ale byloby zle=  f[1] = new Square(*f[0]); - kopiujemy kwadrat f[0].
    //ale tak nie mozna do komputer sie pomyli, ze to z figure
    //dzieki temu *static_cast<Square*>(f[0]) zmieniamy typ wskaznika
    //ze wskaznika na figure na wskaznik na square. dzieki temu mozemy z tego
    //korzystac (bo istnienie)
    f[1] -> scale(2.0); //powieksza nam kwadrat na 2 razy wiekszy

    f[2] = new Square(*static_cast<Square*>(f[0])); //f2 - kwadrat
    f[2] -> scale(4.0);

    f[3] = new Point(50.0, 50.0); //f3 - punkt

    f[4] = new Point(70.0, 70.0); //f4 - punkt

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
