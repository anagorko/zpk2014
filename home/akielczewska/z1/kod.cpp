#include<iostream>
using namespace std;

main(){
    char sz1, sz2;
    cin >> sz1 >> sz2;
    int ascii, cz1, cz2;
    cz1 = (int)sz1 - 48;
    if (sz2=='A') cz2 = 10;
    else if (sz2=='B') cz2 = 11;
    else if (sz2=='C') cz2 = 12;
    else if (sz2=='D') cz2 = 13;
    else if (sz2=='E') cz2 = 14;
    else if (sz2=='F') cz2 = 15;
    else cz2 = (int)sz2 - 48;
    ascii= 16 * cz1 + cz2;
    cout << ascii << endl << (char)ascii;
}

