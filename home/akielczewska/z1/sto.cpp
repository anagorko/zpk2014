#include <iostream>
using namespace std;

main() {
    int a, b, k;
    cin >> a >> b >> k;
    int i=0, j=0;
    // by wi�ksza liczba to a, mniejsza - b:
    if (a<b) {
        int c = a;
        a = b;
        b = c;
    }
    if (b < k)
        i = 0;
    else if (b < 2*k)
        i = 2 * (a/k) + ((b - 2*k) / k);
       // i = b / k;
    else i = 2 * ((a/k) + ((b - 2*k) / k));
 //   j = 2 * ((b/k) + ((a - 2*k) / k));
 //   if (i > j)
        cout << i;
//    else
 //       cout << j;
}


/* problem - w niekt�rych przypadkach wylicza dwa razy za du�o */
