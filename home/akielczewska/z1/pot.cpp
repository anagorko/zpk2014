#include <iostream>
using namespace std;

main() {
    int n;
    cin >> n;
    int k = 1;
    while (k <= n) {
        cout << k << endl;
        k *= 2;
    }
}
