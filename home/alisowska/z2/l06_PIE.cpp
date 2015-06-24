#include <iostream>
using namespace std;
int main(){
    int n; int x;
    cin >> n >> x;
    int tab[n];
    for (int i = 0; i<n; i++)
        cin >> tab[i];
    int pierwszy = -1;
    int ostatni = -1;
    for (int i = 0; i<n; i++){
        if (tab[i]==x){
            pierwszy = i+1;
            break;}
    }
     for (int i = n-1; i>=0; i--){
        if (tab[i]==x){
            ostatni = i+1;
            break;}
    }
    cout <<pierwszy <<" " << ostatni;
}
