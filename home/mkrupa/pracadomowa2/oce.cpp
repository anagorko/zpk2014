#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    int t[n];
    int ocena1 = 0, ocena2 = 0, ocena3 = 0, ocena4 = 0, ocena5 = 0, ocena6 = 0;

    for (int i = 0; i < n; i++){

        cin >> t[i];
        if (t[i]=1)
            ocena1++;
        if (t[i]=2)
            ocena2++;
        if (t[i]=3)
            ocena3++;
        if (t[i]=4)
            ocena4++;
        if (t[i]=5)
            ocena5++;
        if (t[i]=6)
            ocena6++;
    }
    cout << ocena1 << ocena2 << ocena3 << ocena4 << ocena5 << ocena6 << endl;

}

