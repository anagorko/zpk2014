#include <iostream>
using namespace std;

main() {
    int n, m;
    cin >> n >> m;
    int t[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> t[i][j];
        }
    }
    int k = 0; // k to ��czny koszt produkt�w
    // c to tablica przechowuj�ca ceny podukt�w (docelowo po cenie, w jakiej kupi�)
    // nr to tablica przechowuj�ca nr sklepu, w kt�rym kupi� dany produkt
    int c[m], nr[m];
    int n1 = 1;
    int n2 = 2;



    // najpierw jakby wszystko mia�o byc kupione w sklepie nr 1
    for (int j = 0; j < m; j++) {
        c[j] = t[0][j];
        nr[j] = 1;
        k += c[j];
        cout << c[j] << " " << nr[j] << endl;
    }

    // wyb�r pomi�dzy sklepami nr 1 i 2
    for (int j = 0; j < m; j++) {
        if (t[1][j] < c[j]) {
            nr[j] = 2;
            int r = t[1][j] - c[j];
            c[j] = t[1][j];
            k += r;
        }
        cout << c [j] << " " << nr[j] << endl;
    }

/* w tabelach powy�ej, w kt�rych przechowuj� najlepsze dotychczasowe rozwi�zanie,
mam najlepszy wyb�r pomi�dzy sklepami 1 i 2

//roboczo do przechowywania i por�wnywania koszt�w:
int nrr[m];
int cc[m];
int kk = 0;

    for (int i = 2; i < m; i++) {
        // sprawdzam czy taniej ni� w nr1 i nr2 by�oby w nr1 i i+1
        for (int j = 0; j < m; j++) {
            cc[j] = t[0][j];
            kk += cc[j];
            cout << cc[j] << " " << nrr[j] << endl;
        }
        for (int j = 0; j < m; j++) {
            if (t[i][j] < cc[j]) {
                int r = t[i][j] - cc[j];
                c[j] = t[i][j];
                kk += r;
            }
        cout << cc[j] << " " << nrr[j] << endl;
    }
    }
    cout << k;
}

