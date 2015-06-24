#include <iostream>
using namespace std;

int NWD(int a, int b) {
    int r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main() {
    int n;
    cin >> n;
    int x, y;
    cin >> x;
    for (int i = 1; i <= n; i++) {
        cin >> y;
        x = NWD(x,y);
        // cout << x << " " << y << endl;
    }
    cout << x;
}
