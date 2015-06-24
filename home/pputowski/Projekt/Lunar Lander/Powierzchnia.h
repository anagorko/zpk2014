#ifndef POWIERZCHNIA_H_INCLUDED
#define POWIERZCHNIA_H_INCLUDED


class Powierzchnia
{
    double powierzchnia[screen_w][6];
    /* Tablica ktorej pierwsza wartosc to wspolrzedna x a druga oznacza:
    0 - wspolrzedna Y
    1 - Odleglosc statku od tego X
    2 - Wartosc bonusu w tym X

    3 - wspolrzedna Y w zblizeniu
    4 - Odleglosc statku od tego X w zblizeniu
    5 - Wartosc bonusu w tym X w zblizeniu
    */

public:
    Powierzchnia(); // losuje plansze
    void RysujPowierzchnie( int czas, bool zoom );
    // wyswietla plansze. Zmienna czas oznacza opoznienie w oscwiezaniu ekranu podczas wyswietlania kolejnych punktow planszy
    // zoom czy wyswietlona ma byc plansza w przyblizeniu
    void obliczOdleglosci( Statek* s, bool zoom );
    // Obliczane sa odleglosci od planszy dla najnizszego punktu statku
    double Zblizenie( int skala, int x );
    // Generowane jest przyblizenie planszy o dana skale wzgledem punktu o wspolrzednej X
    // Funkcja zwraca wartosc wsporzednej X w oddaleniu jaka stanowi lewa krawedz ekranu w przyblizeniu
    double sprawdzOdleglosci( bool zoom );
    // Zwraca najmniejsza odleglosc statku od planszy
    double bonus( double _x, bool zoom );
    // Zwraca wartosc bonusu kryjacego sie pod wspolrzedna X w zblizeniu lub nie
    double wysokosc( double _x, bool zoom );
    // Zwraca wysokosc Statku nad powierzchnia w miejscu X w zblizeniu lub nie
    int sprawdzWygrana( Statek* s );
    // Zwraca ktory rog statku dotyka powierzchni
    ~Powierzchnia();
};

#endif // POWIERZCHNIA_H_INCLUDED
