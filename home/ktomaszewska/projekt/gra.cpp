#include "gra.h"

int Gra::losuj_liczbe(int a, int b){
    return rand()%(b-a+1)+a;
}

void Gra::rozpocznij_gre(){
    srand( time( NULL ) );

    //klocek obecny
    typ_klocka=losuj_liczbe(0,6);
    rotacja_klocka=losuj_liczbe(0,3);
    pX=5;
    pY=0;

    //klocek kolejny
    n_typ_klocka=losuj_liczbe(0,6);
    n_rotacja_klocka=losuj_liczbe(0,3);
    n_pX=5+10; // na razie, klocek w okienku nastepnego
    n_pY=3;
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
void Gra::rysuj_klocek(){

}

//kolorami
void Gra::rysuj_plasze()
{

}
