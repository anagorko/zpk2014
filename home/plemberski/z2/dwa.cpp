#include <iostream>
using namespace std;

int main(){

    int n, m;
    int razem;
    cin >> n;
    cin >> m;

int koszt[n][n];

//wczytywanie cen
    int t[n][m];
    for( int i=0; i < n; i++) {
        for( int j=0; j < m; j++) {
            cin >> t[i][j];
        }
    }
//wyzerowanie ca³ej tabeli koszt

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            koszt[i][j]=0;
        }
    }
// wczytywanie wszystkich mozliwosci zakupowcyh
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                koszt[i][j]+=min(t[i][k],t[j][k]);
            }
        }
    }

    razem=koszt[0][0];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(koszt[i][j]<razem)
                razem=koszt[i][j];
        }
    }

    cout << razem << endl;
}

