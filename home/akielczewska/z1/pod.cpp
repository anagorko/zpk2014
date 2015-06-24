#include <iostream>
using namespace std;

main () {
    int a, b, k;
    cin >> a >> b >> k;
    int i = 0; // zmienna i zlicza podzielne liczby
    // przesune liczby a,b mozliwie blisko poczatku osi tak, aby zostalo tyle samo liczb podzielnych wewnatrz przedzialu
    b = a % k + (b - a);
    a = a % k;
    i += b/k;
    if (a % k ==0 ) i++;
    cout << i << endl;
}
