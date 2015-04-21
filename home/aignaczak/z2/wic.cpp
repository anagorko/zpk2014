#include <iostream>
using namespace std;

int druga(int t[], int k, int ilosc){
    int x = 0;

    for(int i = 0; i < ilosc; i ++){
        if(t[i] < k && t[i] > x)
            x = t[i];
    }

    return x;
}

int main(){
    int n, wynik;
    int k = 0;
    cin >> n;
    int t[n];

    for(int i = 0; i < n; i++){
        cin >> t[i];
        if(t[i] > k)
            k = t[i];
    }

    wynik = druga(t, k, n);
    cout << wynik;
}
