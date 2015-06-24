#include <iostream>
using namespace std;

int main(){
int n;
cin >> n;
int t[n];

for (int i=0; i<n; i++)
    cin >> t[i];

int m1 = t[0];
int m2 = -1;

for (int i=0; i<n; i++){
    if (m1 <= t[i])
        m1 = t[i];}

for (int i=0; i<n; i++){
    if (t[i] != m1 && m2<= t[i])
        m2 = t[i];
}
    cout << m2;
}
