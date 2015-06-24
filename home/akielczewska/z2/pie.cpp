#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int t[n]; // tablica ze wszystkimi notowaniami
    int a = -1;
    int b = -1; // numery dni potrzebne na wyjsciu
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        if (t[i] == x) {
            b = i+1;
            if (a == -1) {
                a = i+1;
            }

        }
    }
    cout << a << " " << b << endl;
}
