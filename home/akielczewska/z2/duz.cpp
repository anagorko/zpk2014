#include <iostream>
#include <string>
using namespace std;


main() {
    string l1, l2, z;
    char r = '=';// rzeczywiste porównanie dwóch liczb: > lub < lub =
    cin >> l1 >> z >> l2;
    if (l1.size() > l2.size()) {
        r = '>';
    }
    else if (l1.size() < l2.size()) {
        r = '<';
    }
    else {
        int s = l1.size();
        for (int i = s; i > 0; i--) {
            if (l1[i-1] > l2[i-1]) {
                r = '>';
            }
            else if (l1[i-1] < l2[i-1]) {
                r = '<';
            }

        }
    }
    // cout << r << endl;
    bool p = true;
    if (z == "==") {
        if (r != '=') {
            p = false;
        }
    }
    else if (z == "!=") {
        if (r == '=') {
            p = false;
        }
    }
    else if (z == "<") {
        if (r != '<') {
            p = false;
        }
    }
    else if (z == ">") {
        if (r != '>') {
            p = false;
        }
    }
    else if (z == "<=") {
        if (r == '>') {
            p = false;
        }
    }
    else if (z == ">=") {
        if (r == '<') {
            p = false;
        }
    }
     cout << p << endl;
    /*if (p == true) cout << "TAK";
    else cout << "NIE";*/
}
