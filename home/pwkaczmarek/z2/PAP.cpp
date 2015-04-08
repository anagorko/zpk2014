#include <iostream>
#include <math.h>
using namespace std;
// Jezeli zauwazymy, iz z ciagu samych jedynek (zapis binarny) mozemy stworzyc kazda liczbe nie wieksza niz reprezentowana przez
// ten zapis liczbe w systemie dziesietnym, to zadanie (w ogolnej postaci, bez zalozenia, ze mamy co najmniej jedna papryczke danego typu)
// sprowadza sie do znalezienia najdluzszego ciagu jedynek i "przesuniecia" go o pozostala reszte.
// Idee ta mozna porownac z przesuwaniem przedzialow o zadana wartosc.


int main(){
    int n;
    unsigned int suma = 0, potega = 1, rzad = 1;
    cin >> n;
    n++;
    int stan[n];
    for(int i = 0; i < n; i++){
        cin >> stan[i];
        suma += stan[i] * potega;
        potega += potega;
    }
    // wczytano tablice i ustalono ile wynosi suma. Sume te mozna zapisac w postaci binarnej na FLOOR(ln2(suma)) + 1 bitach - taki tez jest rozmiar pomocniczej tablicy
    rzad = int(log2(suma))+ 1;
    unsigned int rozwiniecie[rzad], roznica[rzad];
   // cout << rzad << endl;
    // wyzerowanie rozwiniecie, roznica
    for(int i = 0; i < rzad; i++)
        rozwiniecie[i] = roznica[i] = 0;
    // skopiowanie stan do rzad
    for(int i = 0; i < n; i++)
        rozwiniecie[i] = stan[i];

    // sprowadzenie zapisu do mozliwego zapisu 0, 1, 2
    for(int i = 0; i < rzad; i++){
        if(rozwiniecie[i] > 2){
            if(rozwiniecie[i]%2 == 0){
                rozwiniecie[i+1] += (rozwiniecie[i]/2 - 1);
                rozwiniecie[i] = 2;
            }else{
                rozwiniecie[i+1] += rozwiniecie[i]/2;
                rozwiniecie[i] = 1;
            }
        }
    }
    // wypisanie jak wyglada rozwiniecie
 //   cout << "Rozwiniecie: " << endl;
  //  for(int i = 0; i < rzad; i++)
  //      cout << rozwiniecie[i] << " ";
 //   cout << endl;

    // jest rozwinieta, teraz potrzebuje wyciagnac tabele z samymi jedynkami
    int dlugosc_jedynek = 0, dlugosc_przesuniecia = 0;
    bool koniec_przesuniecia = false;
    for(int i = 0; i < rzad && (rozwiniecie[i]); i++){
        dlugosc_jedynek = i + 1; // wyznaczam dlugosc ciagu samych jedynek lub 2
    }
    int i = rzad - 1;
    while(rozwiniecie[i] == 1 || rozwiniecie[i] == 0){
        dlugosc_przesuniecia = i;
        i--;
    }

    unsigned long long int wynik = 0, przesuniecie = 0;
    potega = 1;
    for(int i = 0; i < dlugosc_jedynek; i++){
        wynik = wynik + wynik + 1; // bo wiem, ze to same 1 lub 2
        if(i < dlugosc_przesuniecia && rozwiniecie[i]>1){
            przesuniecie += potega;
        }
        // jezeli przesuwalibysmy o wartosc wieksza niz reprezentowana przez ciag jedynek, powstalaby "dziura" pomiedzy koniec a (poczatek + przesuniecie)
        potega += potega;
    }
    // i ostatecznie mamy wynik, a wiec kolejna liczbe po wynik + przesuniecie
    cout << wynik + przesuniecie + 1 << endl;
}

