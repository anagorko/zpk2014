#include <iostream>
using namespace std;

main () {
    int n;
    cin >> n;
    int p; // pierwszy najlepszy wynik
    cin >> p;
    int d = 0; // drugi najlepszy wynik
    //cout << d << " " << p << endl;
    int x; //pomocnicza zmienna do przechowywania aktualnie wczytywanej wartosci
    for (int i = 1; i < n; i++) {
        cin >> x;
        if (x >= p) {
            d = p;
            p = x;
        }
        else if (x > d) {
            d = x;
        }
        //cout << d << " " << p << endl;
    }
    cout << d;
}
