#include <iostream>
using namespace std;

int main() {
    int n, a, x = -1, y = -1;
    cin >> n >> a;
    int t[n];
    for (int i = 0; i < n; i++){
        cin >> t[i];
        if (t[i] == a && x == -1)
            x = i + 1;
        else if (t[i] == a && x != -1)
            y = i + 1;
}
        if ( x != -1 && y == -1)
            x = y;
        cout << x << " " << y << endl;

}
