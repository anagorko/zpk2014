#include <iostream>
#include <cmath>
using namespace std;

int main() {
    unsigned short k;
    cin >> k;
    unsigned short t[k + 1];
    unsigned int wynik = 0;
    for (unsigned short i = 0; i < k + 1; ++i) {
        cin >> t[i];
        wynik += t[i] * pow(2, i);  //pow - funkcja potegowa z boblioteki std
    }
    cout << ++wynik << endl;
}
