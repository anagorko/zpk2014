#include<iostream>
#include "point.cpp"

using namespace std;

int main(){
    Point p1(5);
    cout << "na poczatku punkt p1 to: " << p1 << endl;

    cout << "podaj wspolrzedne punktu p ( , , )"<<endl;
    int n;
    cin >> n;
    p1.set_coordinate(2,n);
    cout << "teraz punkt p1 to: " << p1 << endl;
}
