#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

#include<allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>


const int screen_w = 1440;
const int screen_h = 810;

 int poziomy_o[2][9][16] = 
 {
     {
                        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,0,0,0,0,0,0,0,1,0,0,1,1,1},
                        {1,1,1,0,0,0,0,0,0,0,1,0,0,1,1,1},
                        {1,1,1,0,0,0,1,0,0,0,1,0,0,1,1,1},
                        {1,0,0,0,0,0,1,0,0,0,1,0,0,1,1,1},
                        {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1},
                        {1,0,3,0,2,0,1,0,0,0,0,0,0,0,0,1},
                        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
                        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
     },
     {
                        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,0,1,0,0,0,0,0,0,0,1,0,0,1,1,1},
                        {1,0,1,0,0,0,0,0,0,0,1,0,0,1,1,1},
                        {1,0,1,0,0,0,1,0,0,0,1,0,0,1,1,1},
                        {1,0,0,0,0,0,1,0,0,0,1,0,0,1,1,1},
                        {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1},
                        {1,0,3,0,2,0,1,0,0,0,0,0,0,0,0,1},
                        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
                        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
      }
  }

// int poziomy_p[2][9][16] = TODO

class Plansza
{
 int p[9][16];
 int o[9][16];
 
// wypelnienie obiektow: 0 - puste; 1 - sciana; 2 - pudelko; 3 - ludzik

public:
    void wczytaj_plansze(int numer_poziomu)
    {
        // mozna tu zrobic kopiowanie z poziomy_o i poziomy_p

        // wypelnienie podlogi; 0 - puste; 1- pole magazynu
        for (int i=0; i<16; i++){
            for (int j=0; j<9; j++)
                p[j][i]= poziomy_p[numer_poziomu][j][i];
        }

        // wypelnienie obiektow
    
        // TODO
    }

    int podloga(int j, int i)
    {
        return p[j][i];
    }
    
    int obiekt(int j, int i)
    {
        return o[j][i];
    }
    
    void wykonajRuch(int kierunek, int &energia); // 0 - gora; 1 - prawo; 2 - dol; 3 - lewo
        // ta funkcja sprawdza, czy jest dosc energii na wykonanie ruchu
        // jezeli wykona ruch, to zeruje energie
        
    // inny wariant: wykonajRuchWGore(); wykonajRuchWPrawo(); etc.
    
    bool czyKoniec();
    
};


int rysuj_plansze(Plansza &p){

// tworzenie wskaznikow do elementow planszy
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_BITMAP  *pole   = NULL;
ALLEGRO_BITMAP  *sciana   = NULL;
ALLEGRO_BITMAP  *bambus   = NULL;
ALLEGRO_BITMAP  *magazyn   = NULL;
ALLEGRO_BITMAP  *panda   = NULL;

// sprawdzenie inicjalizacji allegro
if(!al_init()) {
    return 1;
}

if(!al_init_image_addon()) {
    return 1;
}

// tworzy okno
display = al_create_display(screen_w, screen_h);

// sprawdzenie czy okno się utworzylo
if(!display) {
    return 1;
}

// wczytanie elementow planszy
sciana = al_load_bitmap("sciana.png");
pole = al_load_bitmap("pole.png");
bambus = al_load_bitmap("bambus.png");
magazyn = al_load_bitmap("magazyn.png");
panda = al_load_bitmap("panda.png");

// sprawdzenie czy elementy sie wczytaly
if(!pole || !sciana || !bambus || !magazyn) {
    al_destroy_display(display);
    return 1;
}

// koloruje okno na czarno
al_clear_to_color(al_map_rgb(0,0,0));

// rysuje elementy planszy
for (int j=0; j<9; j++){
    for (int i=0; i<16; i++){
        if (p.obiekt(j,i) ==1 && p.podloga(j,i) ==0)
            al_draw_bitmap(sciana,i*90,j*90,0);
        else if (obiekty[j][i]==0 && podloga[j][i]==0) // TODO
            al_draw_bitmap(pole,i*90,j*90,0);
        else if (obiekty[j][i]==2 && podloga[j][i]==0)
            al_draw_bitmap(bambus,i*90,j*90,0);
        else if (obiekty[j][i]==3 && podloga[j][i]==0)
            al_draw_bitmap(panda,i*90,j*90,0);
        else if (podloga[j][i]==1)
            al_draw_bitmap(magazyn,i*90,j*90,0);
    }
}

// wyswietla plansze
al_flip_display();
al_rest(10.0);

// usuwa wksazniki
al_destroy_display(display);
al_destroy_bitmap(sciana);
al_destroy_bitmap(pole);
al_destroy_bitmap(bambus);
al_destroy_bitmap(magazyn);
al_destroy_bitmap(panda);

return 0;

}

int main(int, char**){


    // TODO: głowna pętla
    //   1. przetworzenie zdarzeń - 
    //     a. co 1/60 sekundy - rysowanie planszy
    //     b. reakcja na strzalki (wykonajRuch()) - z uwzglednieniem energii
    
Plansza p; // stworzenie planszy
p.wczytaj_plansze(); // wczytanie planszy
p.rysuj_plansze(); // rysowanie planszy


}
