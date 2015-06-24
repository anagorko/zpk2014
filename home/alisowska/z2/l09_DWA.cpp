#include <iostream>
#include <cmath>
using namespace std;
int main(){
int n, m;
cin >> n >> m;
int t[n][m];
for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j)
        cin >> t[i][j];
int suma[n][n];
for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
        suma[i][j] = 0 ;
for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
        for (int k=0; k<m; ++k)
            suma[i][j]+=min(t[i][k],t[j][k]);
int wynik = suma[0][0];
for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
        if (suma[i][j]<wynik)
            wynik=suma[i][j];
cout << wynik;
}
