#include <iostream>
#include <algorithm>
using namespace std;

int main(){
int a, b;
cin>>a>>b;

int tab[a][b], suma, suma2;

for(int i=0; i<a; i++)
    for(int j=0; j<b; j++)
        cin>>tab[i][j];


for(int i=0; i<a-1; i++)
for(int j=i+1; j<a; j++){
    suma=0;
    for(int x=0; x<b; x++)
        suma=suma+min(tab[i][x],tab[j][x]);
    if(i<1 && j<2) suma2 = suma;
    else suma2 = min(suma,suma2);

}
cout<<suma2;

}






