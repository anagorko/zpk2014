#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n, wypisz = 0;
    cin >> n;

    if (n % 4 == 1)
        wypisz = 2;
    else if (n % 4 == 2)
        wypisz = 4;
    else if (n % 4 == 3)
        wypisz = 8;
    else if (n == 0)
        wypisz = 1;
    else
        wypisz = 6;
cout << wypisz << endl;
}
