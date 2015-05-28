#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    int n, wynik;
    cin >> n;

        if (n == 0)
            wynik = 1;
        if (n%4 == 0)
            wynik = 6;
        if (n%4 == 1)
            wynik = 2;
        if (n%4 == 2)
            wynik = 4;
        if (n%4 == 3)
            wynik = 8;

    cout << wynik << endl;


}
