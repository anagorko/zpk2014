#include <iostream>
using namespace std;

void zmien(int &a, int &b){
    int c = 0;
    if (b > a){
        c = a;
        a = b;
        b = c;
    }
}

int NWD(int a, int b){
    while (a != b){
        zmien(a, b);
        a = a - b;
    }
    return a;
}


int main() {
    int n;
    cin >> n;
    int t[n];

    for(int i = 0; i < n; i++){
        cin >> t[i];
    }

    for(int i = 1; i < n; i++){
        t[i] = NWD(t[i], t[i - 1]);
    }

    cout << t[n-1];
}
