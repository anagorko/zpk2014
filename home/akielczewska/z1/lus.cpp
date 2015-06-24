#include <iostream>
using namespace std;

main() {
    int n;
    cin >> n;
    // obciecia zer ktore maja nie byc wyswietlone
    while (n%10 == 0) {
        n /= 10;
    }
    while (n != 0) {
        cout << n%10;
        n /= 10;
    }
}
