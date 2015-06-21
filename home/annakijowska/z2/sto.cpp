#include <iostream>
using namespace std;

int main() {
    int A, B, K;
    int liczba=0;
    cin >> A >> B >> K;

    if (B>K && A>K){
        liczba=(A/K)*2 +(B/K)*2-4;
    }
    else if (A==K && B==K)
        liczba=1;
    else
        liczba=0;
    cout << liczba << endl;

}

