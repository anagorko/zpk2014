#include <iostream>
#include <string>
using namespace std;

main() {
    string s;
    cin >> s;
    int n = s.size();
    string o = s; // zeby napis o byl takiej dlugosci jak s
    // cout << n << endl;
    for (int i = n-1, j = 0; i >= 0; i--, j++) {
        o[j] = s[i];
        //cout << o[i] << endl;
        //cout << o << endl;
    }
    //cout << o;
    if (o == s) {
        cout << "TAK";
    }
    else cout << "NIE";
}
