#include <iostream>
#include <math.h> // do poteg
using namespace std;
int main(){
    int k;
    cin >> k;
    int tab[k+1];
    int najmniejsza = 0;
    for (int i=0; i<k+1; i++)
        cin >> tab[i];
    for (int i=0; i<k+1; i++)
        najmniejsza += tab[i]* pow(2, i); // mozliwe do uzyskania
    cout << najmniejsza + 1;
}
