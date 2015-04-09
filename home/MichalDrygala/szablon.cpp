#include <iostream>
//#include <algorithm> // min, swap
//#include <string>
//#include <cstdlib> // warosc bezwzgledna abs
//#include <iomanip> // do liczb rzeczywistych, by podawac okreslona liczbe vyfr po przecinku
//#include <cmath> / zeby byly funkcje sqrt, abs, sin itd.
//#include <math.h> // stala pi - M_PI   stala e M_E
using namespace std;

int main() {
   i: &&
   lub: ||
   nie: !=

   a += b; //a = a + b
   a -= b;
   a *= b;
   a /= b;
   a %= b;
   a++; //a += 1
   a--;

    char znak; //pobieramy jakis znak, np. litere
    cout << (int)znak << endl; //wypisze liczbe (kod / numer w kodzie ASCII tej litery)

    int numer; //pobiera liczbe
    cin >> numer;
    cout << (char)('a' + numer - 1); //do kodu litery "a" dodaje liczbe oraz odejmuje 1. konwertuje liczbe na znak, wypisuje znak.

    int kod; //gorsza konwersja
    char znak;
    cin >> kod;
    znak = kod;

    // a/b= wynik
    // jesli chcemy zaokraglic w gore to stosuje sie
    // (a + b - 1) / b = wynik zaokraglony w gore

    while (warunek)   //do poki jest spelniony warunek wykonuj instrukcje
    {   instrukcja1;    /warunkiem moze byc takze liczba, jesli jest dodatnia to warunek jest ok i instrukcje sie zrobia
        instrukcja2;    /jesli liczba jest zero to warunek nie jest spelniony wiec instrukcje sie nie wypelnia
    }

    for(int i = poczatek; i <= koniec; i++)
        instrukcja;

    for (instrukcja_poczatkowa; warunek_stopu; krok_petli)
    instrukcja;

instrukcja_pocz¹tkowa;
sprawdŸ warunek_stopu - jeœli fa³szywy, to koniec
instrukcja;
krok_pêtli;
sprawdŸ warunek_stopu - jeœli fa³szywy, to koniec
instrukcja;
krok_pêtli;
...

    int t[n]; // int - kazda zmienna w tabloicy bedzie int, "t" to nazwa talbicy,
                //n to rozmiat tablicy ktory trzeba znac wczesniej przed zadeklarowaniem. t[0].......t[n-1]


    bool a = true; // albo a = false

    string a = "napis";
    a.size(); // dlugosc napisu
    cin >> a; //tekst jest wczytywany do pierwszej spacji

    //napisy sa w "", nawet jesli jest to tylko jeden znak to i tak ""
    // ale znaki sa w '', np. jesli przyrownujemy pierwszy znak napisu do litery 'K' to uzywamy ''


    //Funkcje

    int min(int a, int b){  /pierwsze int oznacza ze funkcja w wyniku daje int
        if (a < b)          / a i b to argumenty funkcji
            return a;       / return to zwracanie funkcji
        else                / min to nazwa funkcji
            return b;       / funkcja konczy sie po return, a powinno byc to return bo bez niego zwroci zly wynik
    }
    /jesli wywolamy funkcje z danym argumentem 'n' i ta funkcja zmieni nam ten argument, to po zakonczeniu dzialania funkcji i
    /po wywolaniu tego argumentu on wciaz ma stara wartosc. chyba ze w funkcji przed nazwa zmiennej dodajmy & co znaczy, ze wartosc
    /tego argumentu po zmianach zostanie zapisania (wtedy musi podac zmienna, nie moze podac stalej)

    /jesli nie chcemy zeby funkcja nam cos zwracala to pisze "void" zamiast typu zmiennej przed nazwa funkcji. piszemy tak jak np chcemy zeby
    / funkcja zamienila nam argumenty, ale nie musi nic zwracac

    /jesli chcemy zeby funkcja zwrocila nam rozne wartosci np. liczbe i tekst to piszemy "struct" zamiast np. int przed nazwa fun.
    / pozniej w programie jak wykorzystujemy te funkcje struct to piszemy nanzwe funkcji a pozniej nazwe zmiennej np. struct o;
    /

    double
    / to sa liczby rzeczywiste np. 123.45
    #include <iomanip>
    setprecision(2) << fixed;    /zeby byly dwa miejsca po przecinku (fixed mowi o tym ze 2 cyfry po przecinku a nie ze ogolnie dwie cyfry)

    #include <cmath>
    sqrt(x) /pierwiastek kwadratowy
    pow(a, n) / a do potegi n (n nie musi byc calkowite)
    abs(a) / wartosc bezwzgledna
    round(x) / zaokraglenie do najblizszje liczby calkkowitej
    floor(x) / calosc z tej liczby -
    cell(x) / floor(x) + 1
    sin(x) cos(x) tan(x) log(x)

    //tablica dwu-wymiarowa
    int t[100][100]  /t[i][j]
}
