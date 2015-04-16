#include <iostream>
using namespace std;

class A
{
public:
    string name; //obiekt name - tekst

    A() {
        name = "A"; //przypisujemy zmiennej name wartosc A
    }

    void hello() {
        cout << "My name is " << name << "." << endl; //metoda ktora wypisuje tresc
    };
};

class B : public A // klasa B dziedzi z klasy A
{
public:
    B() {
        name = "B"; //wlasny konstruktor klasy B (mog³oby go nie byæ, wówczas by³by
                    //u¿ywany konstruktor z klasy A. ale jesli mamy oddzielny kontruktor
                    //w nowej klasie, to on jest wywolywany, a nie ten z klasy z ktorej
                    //dziedziczy
       };
        void hello(){
        cout << "hi! " << endl; //metoda ktora wypisuje tresc, ale z klasy B, nazwa metody taka sama
        A::hello(); //gdy chcemy wrocic do metody z klasy A, to mozemy
    };

};

int main()
{
    A a;
    a.hello();

    B b;
    b.hello();
}
