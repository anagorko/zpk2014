#include <iostream>
using namespace std;
int main(){
int n;
cin >> n;
int tablica[n];
for (int i=0; i<n; i++)
    cin >> tablica[i];

for (int i = 0; i<n; i+=2)
    cout << tablica[i]<<" ";
cout <<endl;
for (int i = 1; i<n; i+=2)
    cout << tablica[i]<<" ";
}
