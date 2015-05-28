#include <iostream>
using namespace std;

class Plansza {

    int t[4][4];

    int wynik;

    void ustawLosowaLiczbe();

public:
    Plansza() {
        wynik = 0;
    }
    
    void ustawPozycjePoczatkowa();
    
    // 1 wariant: void wykonajRuch(int nr); // 0 - gora, 1 - prawo, ..
    // 2 wariant: void wykonajRuchWDol(); // itd.

    int zawartoscPola(int w, int k);
    
    bool koniecGry();
    
    int wynik();
    
};

int main() {


}
