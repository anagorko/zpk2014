#include "gra.h"

int Gra::losuj_liczbe(int a, int b){
    return rand()%(b-a+1)+a;
}

void Gra::rozpocznij_gre(){
    srand( time( NULL ) );

    //klocek obecny
    typ_klocka=losuj_liczbe(0,6);
    rotacja_klocka=losuj_liczbe(0,3);
    pX=0;
    pY=5;

    //klocek kolejny
    n_typ_klocka=losuj_liczbe(0,6);
    n_rotacja_klocka=losuj_liczbe(0,3);
    n_pX=3; // na razie, klocek w okienku nastepnego
    n_pY=5+80;
}

// przejscie z nastepnego na biezacy
void Gra::generuj_klocek(){
    typ_klocka=n_typ_klocka;
    rotacja_klocka=n_rotacja_klocka;
    pX=5;
    pY=0;

    n_typ_klocka=losuj_liczbe(0,6);
    n_rotacja_klocka=losuj_liczbe(0,3);
}

//kolorami
void Gra::rysuj_klocek(int pX, int pY, int typ_klocka, int rotacja_klocka){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (k->klocki[typ_klocka][rotacja_klocka][i][j] != 0)
                al_draw_filled_rectangle(61 + 30 * (pX + j) , 45 + 30 * (pY + i), 91 + 30 * (pX + j), 74 + 30 * (pY + i), al_map_rgb(0,0,0));
            else
                al_draw_filled_rectangle(61 + 30 * (pX + j) , 45 + 30 * (pY + i), 91 + 30 * (pX + j), 74 + 30 * (pY + i), al_map_rgb(255,255,255));
        }
    }
}
