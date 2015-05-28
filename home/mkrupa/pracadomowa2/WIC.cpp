#include <iostream>

using namespace std;

int najwieksza_mniejsza(int t[], int n, int a){
int wicemistrz = 0;
    for(int i = 0; i < a; i ++){
    if(t[i] < n && t[i] > wicemistrz)
        wicemistrz = t[i];
}
    return wicemistrz;
}
int main(){
int y, n = 0, wicemistrz;
cin >> y;
int t[y];
    for(int i = 0; i < y; i++){
    cin >> t[i];
    if(t[i] > n)
        n = t[i];
}
    wicemistrz = najwieksza_mniejsza(t, n, y);
    cout << wicemistrz << endl;
}
