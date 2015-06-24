#ifndef STATEK_H_INCLUDED
#define STATEK_H_INCLUDED

class Statek
{
    double punkty[10][2];
    // Statek to 10 punktow dla ktorych przechowywane sa wspolrzedne x i y
    double plomien[6][2];
    // Za statkiem po nacisnieciu sztrzalki do przeodu pojawia sie plomien reprezentowany przez 6 wspolrzednych
    double kat;
    // zapamietanie kata potrzebnego do obliczania pedu
    float bezwladnoscX, bezwladnoscY, skala;
    // Zapamietanie pedu statku oraz skali w jakiej znajduje sie statek w danej chwili
    bool go, lewo, prawo, zoomS;
    // Zmienne uzywane do sterowania statkiem oraz zmienna mowiaca czy statek znajduje sie w przyblizeniu
    int paliwo;
    // zmienna pamietajaca ile jest jeszcze paliwa na pokladzie
    int sumaObrotowPlus, sumaObrotowMinus;
    // Dodatkowe zmienne potrzebne do obracania statu podczas przyblizania
    float czas;
    // Czas gry

public:
    Statek();
    void obliczWspol( double x, double y, double skala );
    // Oblicza wspolrzedne statku wzgledem zadanego srodka oraz skali w jakiej ma sie znalezs
    void WyczyscStatek();
    // Czysci statek z planszy
    void WyswietlStatek();
    // Wyswietla statek
    void ObrocStatek( double x );
    // Obraca statek wzgledem zadanego kata
    void PchnijStatek();
    // Przemieszcza statek do przodu
    double WspolStatku( int x, int y );
    // Zwraca wspolrzedna statku ( punkty[x][y] )
    void Grawitacja( const float &_czas );
    // Symuluje dzialanie grawitacji na statek. Zmienna czas jest potrzebna do opoznienia odswiezania informacji o paliwie
    void Lec( bool przod );
    void Lewo( bool L );
    void Prawo( bool P );
    // Powyzsze ustwaiaja wartosci zmiennych bool w klasie
    void Ruch( const float &_czas );
    // Powoduje uruchomienie wszystkich metod zwiazanych z ruchem, zmienna czas jest przekazywana do Grawitacja()
    void Restart( int _paliwo );
    // Restart samolotu do pozycji poczatkowej z zadana iloscia paliwa
    void Zblizenie( double x, double y, double skala );
    // Powoduje przeskalowanie statku o srodku w zadanych wspolrzednych
    int ilePaliwa();
    // Zwraca wartosc paliwa
    float predkoscX();
    // Zwraca wartosc predkosci w pionie
    float predkoscY();
    // Zwraca wartosc predkosci w poziomie
    ~Statek();
};

#endif // STATEK_H_INCLUDED
