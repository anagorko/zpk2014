#include <iostream>
using namespace std;
int main(){
    int telefon;
    int rok;
    cin >> telefon >> rok;
    int wynik = telefon % 10;
    wynik *= 2;
    wynik += 5;
    wynik *= 50;
    wynik += 1764;
    wynik -= rok;
    cout << wynik;
}
