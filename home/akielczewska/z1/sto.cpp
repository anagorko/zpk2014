#include <iostream>
using namespace std;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    int i=0, j=0;
    // by wieksza liczba to a, mniejsza - b:
    if (a < b) {
        int c = a;
        a = b;
        b = c;
    }
    if (b < k)
        i = 0;
    else if (b < 2* k)
        i = (a / k) * (b / k);
    else i = 2 * ((a / k - 1) + (b / k - 1));
    cout << i;
}


/* problem - w niektórych przypadkach wylicza dwa razy za duzo */
