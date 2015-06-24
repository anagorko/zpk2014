#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int tab[n];
    for (int i=0; i<n; i++)
        cin >> tab[i];
    for (int i=1; i<=6; i++){
        int suma = 0;
        for (int j=0; j<n; j++){
            if (tab[j]==i)
                suma++;}
        cout << suma << " ";
    }
}
