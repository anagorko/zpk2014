#include <iostream>
using namespace std;

int main(){
    int n = 1, m = 1;
    int wynik;
    int k = 0;
    cin >> n >> m;
    int t[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> t[i][j];
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            for(int z = 0; z < m; z++){
                if(t[i][z] < t[j][z])
                    k += t[i][z];
                else
                    k += t[j][z];
            }

         if(i == 0 && j == 1)
            wynik = k;
         if(k < wynik)
            wynik = k;
            k = 0;
        }
    }
    cout << wynik << endl;
}
