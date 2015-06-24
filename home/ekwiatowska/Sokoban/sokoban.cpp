#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

#include<allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>


const int screen_w = 1120; /* szerokosc ekranu */
const int screen_h = 700; /* wysokosc ekranu */
const float FPS = 60.0; /* ilosc klatek na sekunde */
bool quit=false; /* zmienna sprawdzajaca czy ktos chce zamknac gre*/

/* w grze dostpene sa trzy poziomy trudnosci
1 - 1 pudelko
2- 3 pudelka
3 5 pudelek */

/* tablica tablic reprezentujacych obiekty - 1 - sciana, 2 - pudelko, 3- gracz */
int poziomy_o[3][9][16] =
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
                        {1,1,1,0,0,1,0,0,0,0,0,0,0,1,1,1},
                        {1,0,1,0,0,1,1,1,0,0,0,2,0,0,1,1},
                        {1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1},
                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                        {1,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1},
                        {1,0,3,0,2,0,0,2,0,0,0,0,1,0,0,1},
                        {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
                        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
      },
      {
                        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,0,0,1,0,0,0,0,0,0,0,1,1,1},
                        {1,0,0,0,0,1,1,1,0,2,0,2,0,0,1,1},
                        {1,0,0,2,0,1,0,0,0,0,0,0,0,0,0,1},
                        {1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1},
                        {1,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1},
                        {1,0,3,0,2,0,0,2,0,0,0,0,1,0,0,1},
                        {1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,1},
                        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
      }
};
/* tablica tablic reprezentujacych podloge - 0 - puste pole, 1 - pole magazynu */

int poziomy_p[3][9][16] =
 {
     {
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     },
     {
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      },
      {
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      }
};
/* wspolrzedne i energia gracza*/
int x;
int y;
int energia;


class Plansza
{
 int p[9][16]; /* tablica reprezentujaca podloge */
 int o[9][16]; /* tablica reprezentujaca obiekty */

public:
    void wczytaj_plansze(int numer_poziomu) /* wczytuje plansze dla wybranego przez uzytkownika poziomu*/
    {
        for (int i=0; i<16; i++){
            for (int j=0; j<9; j++){
                p[j][i]= poziomy_p[numer_poziomu][j][i];
                o[j][i]= poziomy_o[numer_poziomu][j][i];
                if (o[j][i]==3)
                {
                    x=i;
                    y=j;
                }
            }
        }

    }

    int podloga(int j, int i)
    {
        return p[j][i];
    }

    int obiekt(int j, int i)
    {
        return o[j][i];
    }

    void wykonajRuch(int kierunek, int &energia){  /* wykonywanie ruchu: 0 - gora; 1 - prawo; 2 - dol; 3 - lewo*/
        if (energia<10) /* gracz moze wykonac ruch jezeli energia jest wieksza od 10, a przesunac pudelko jezeli energia jest niemniejsza niz 30*/
            return;
        else
        {
            if (kierunek==0){ //ruch w gore
                if (obiekt(y-1,x)==0){
                    o[y-1][x]=3;
                    o[y][x]=0;
                    y=y-1;
                    energia=0;
                }
                else if (obiekt(y-1,x)==2){
                    if (energia>=30){
                        if (obiekt(y-2,x)==0){
                            o[y-2][x]=2;
                            o[y-1][x]=3;
                            o[y][x]=0;
                            y=y-1;
                            energia=0;
                        }
                    }

                }
            }

            else if (kierunek==2){ //ruch w dol
                if (obiekt(y+1,x)==0){
                    o[y+1][x]=3;
                    o[y][x]=0;
                    y=y+1;
                    energia=0;
                }
                else if (obiekt(y+1,x)==2){
                    if (energia>=30){
                        if (obiekt(y+2,x)==0){
                            o[y+2][x]=2;
                            o[y+1][x]=3;
                            o[y][x]=0;
                            y=y+1;
                            energia=0;
                        }
                    }
                }
            }

            else if (kierunek==1){ //ruch w prawo
                if (obiekt(y,x+1)==0){
                    o[y][x+1]=3;
                    o[y][x]=0;
                    x=x+1;
                    energia=0;
                }
                else if (obiekt(y,x+1)==2){
                    if (energia>=30){
                        if (obiekt(y,x+2)==0){
                            o[y][x+2]=2;
                            o[y][x+1]=3;
                            o[y][x]=0;
                            x=x+1;
                            energia=0;
                        }
                    }
                }
            }

            else if (kierunek==3){ //ruch w lewo
                if (obiekt(y,x-1)==0){
                    o[y][x-1]=3;
                    o[y][x]=0;
                    x=x-1;
                    energia=0;
                }
                else if (obiekt(y,x-1)==2){
                    if (energia>=30){
                        if (obiekt(y,x-2)==0){
                            o[y][x-2]=2;
                            o[y][x-1]=3;
                            o[y][x]=0;
                            x=x-1;
                            energia=0;
                        }
                    }
                }
            }
        }
    }

    bool czyKoniec(){ /* funkcja czy wszystkie pudelka znajduja sie w magazynie*/
        for (int i=0; i<16; i++){
            for (int j=0; j<9; j++){
                if (podloga(j,i)==1 && obiekt(j,i)!=2)
                    return false;
            }
        }
        return true;
    }

};
/* wskazniki dla elementów graficznych gry */
ALLEGRO_BITMAP  *pole   = NULL;
ALLEGRO_BITMAP  *sciana   = NULL;
ALLEGRO_BITMAP  *bambus   = NULL;
ALLEGRO_BITMAP  *magazyn   = NULL;
ALLEGRO_BITMAP  *panda   = NULL;
ALLEGRO_BITMAP  *zajete   = NULL;
ALLEGRO_BITMAP  *menu   = NULL;
ALLEGRO_BITMAP  *poziomy   = NULL;
ALLEGRO_BITMAP  *gratulacje   = NULL;
ALLEGRO_BITMAP  *koniec   = NULL;
ALLEGRO_BITMAP  *instrukcja   = NULL;
ALLEGRO_BITMAP  *pomoc   = NULL;

/* ladowanie elementow graficznych gry */
void zaladuj_bitmapy(){

    sciana = al_load_bitmap("sciana.png");
    pole = al_load_bitmap("pole.png");
    bambus = al_load_bitmap("bambus.png");
    magazyn = al_load_bitmap("magazyn.png");
    panda = al_load_bitmap("panda.png");
    zajete = al_load_bitmap("zajete.png");

    menu = al_load_bitmap("menu.png");
    poziomy = al_load_bitmap("poziomy.png");
    gratulacje = al_load_bitmap("gratulacje.png");
    koniec = al_load_bitmap("koniec.png");
    instrukcja = al_load_bitmap("instrukcja.png");
    pomoc = al_load_bitmap("pomoc.png");

}

/* funkcja rysujaca plansze */
int rysuj_plansze(Plansza &p){

    // sprawdzenie czy elementy sie wczytaly
    if(!pole || !sciana || !bambus || !magazyn || !panda || !zajete) {
        return 3;
    }

    // koloruje okno na bialo
    al_clear_to_color(al_map_rgb(255,255,255));

    // rysuje elementy planszy
    for (int j=0; j<9; j++){
        for (int i=0; i<16; i++){
            if (p.obiekt(j,i) ==1 && p.podloga(j,i) ==0)
                al_draw_bitmap(sciana,i*70,j*70,0);
            else if (p.obiekt(j,i)==0 && p.podloga(j,i)==0)
                al_draw_bitmap(pole,i*70,j*70,0);
            else if (p.obiekt(j,i)==2 && p.podloga(j,i)==0)
                al_draw_bitmap(bambus,i*70,j*70,0);
            else if (p.obiekt(j,i)==3)
                al_draw_bitmap(panda,i*70,j*70,0);
            else if (p.podloga(j,i)==1 && p.obiekt(j,i)==0)
                al_draw_bitmap(magazyn,i*70,j*70,0);
            else if (p.podloga(j,i)==1 && p.obiekt(j,i)==2)
                al_draw_bitmap(zajete,i*70,j*70,0);
        }
    }
    /* rysuje pomoc dla gracza */
    al_draw_bitmap(pomoc,0,630,0);

    // wyswietla plansze
    al_flip_display();

    return 0;

}

/* funkcja wczytujaca wybrany ekran: menu, instrukcja, poziomy lub gratulacje*/
int ekran(Plansza &p, ALLEGRO_BITMAP *nazwa){

    // sprawdzenie czy element sie wczytal
    if(!nazwa) {
        return 3;
    }
    /* rysuje wybrany ekran */
    al_draw_bitmap(nazwa,0,0,0);

    // wyswietla ekran
    al_flip_display();

    return 0;
}

/* funkcja reprezentujaca etap gry */
int graj(Plansza &p, int poziom, ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_TIMER *timer){

    bool narysuj = true;
    bool idz [4] = {false, false, false, false};

    while (p.czyKoniec()==false){

        // kolejka zdarzeñ
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER) {

            energia=energia+1;

            for (int i=0; i<4; i++){
                if (idz[i]) {
                    p.wykonajRuch(i,energia);
                    narysuj = true;
                }
            }

        }

        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            quit=true;
            break;
        }

        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            narysuj = true;

            switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_UP: /* ruch w gore */
                    idz[0] = true;
                    break;
                case ALLEGRO_KEY_LEFT: /* ruch w lewo */
                    idz[3] = true;
                    break;
                case ALLEGRO_KEY_RIGHT: /* ruch w prawo */
                    idz[1] = true;
                    break;
                case ALLEGRO_KEY_DOWN: /* ruch w dol */
                    idz[2] = true;
                    break;
                case ALLEGRO_KEY_R: /* resetowanie planszy */
                    p.wczytaj_plansze(poziom);
                    break;
                case ALLEGRO_KEY_W: /* wyjscie z gry */
                    quit=true;
                    return 0;
                case ALLEGRO_KEY_M: /* przejscie do menu*/
                    return 1;
            }
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
            switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    idz[0] = false;
                    break;
                case ALLEGRO_KEY_LEFT:
                    idz[3] = false;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    idz[1] = false;
                    break;
                case ALLEGRO_KEY_DOWN:
                    idz[2] = false;
                    break;
            }
        }

        // rysowanie planszy
        if (narysuj) {
            rysuj_plansze(p);
            narysuj = false;
        }
    };


return 0;

}
/* funkcja odpowiadajaca za etap gratulacji*/
int wygrana(Plansza &p, int poziom, ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_TIMER *timer){

    while (quit==false){

    /* wyswietlenie gratulacji koncowych */
    if (poziom==2)
        ekran(p, koniec);
    else
        ekran(p, gratulacje);

    /* kolejka zdarzen */
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);

    if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            quit=true;
            break;
    }

    else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
        switch(ev.keyboard.keycode) {
                    case ALLEGRO_KEY_N: /* wybranie nastepnego poziomu */
                        if (poziom<2){
                            poziom=poziom+1;
                            p.wczytaj_plansze(poziom);
                            if (graj(p, poziom, display, event_queue, timer)==1)
                                return 0;
                        }
                        break;

                    case ALLEGRO_KEY_Z: /* wybranie ponownie tego samego poziomu */
                        if (poziom<2){
                            p.wczytaj_plansze(poziom);
                            if (graj(p, poziom, display, event_queue, timer)==1)
                                return 0;
                        }
                        break;

                    case ALLEGRO_KEY_W: /* wyjscie z gry */
                        quit=true;
                        return 0;

                    case ALLEGRO_KEY_M: /* powrot do menu */
                        if (poziom == 2)
                            return 1;


            }
        }


    }
}


int main(int, char**){

    Plansza p; // stworzenie planszy

    /* inicjalizcja allegro */
    if (!al_init() || !al_install_keyboard() || !al_init_image_addon()) {
            cout << "Blad inicjalizacji." << endl;
            return 3;
    }

    ALLEGRO_DISPLAY *display = al_create_display(screen_w, screen_h);
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

    if (display == NULL || timer == NULL || event_queue == NULL) {
        cout << "Blad inicjalizacji." << endl;
        return 4;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    zaladuj_bitmapy();

    al_start_timer(timer);

    while (quit==false){
        ekran(p, menu);

        // kolejka zdarzeñ
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                break;
        }

        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_W: /* wyjscie z gry */
                    quit=true;
                    break;

                case ALLEGRO_KEY_I: /* wyswietlenie instrukcji */
                    {
                        bool instr=false;

                        while (instr==false){
                            ekran(p, instrukcja);

                            ALLEGRO_EVENT ev;
                            al_wait_for_event(event_queue, &ev);

                            if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                                quit=true;
                                break;
                            }

                            if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                                switch(ev.keyboard.keycode) {
                                    case ALLEGRO_KEY_M: /* powrot do menu */
                                    instr=true;
                                break;
                                }
                            }

                        }

                    }
                    break;

                case ALLEGRO_KEY_G: /* start gry - przejscie do wyboru poziomu */
                {
                    ekran(p, poziomy);

                    bool poziom=false;

                    while (poziom==false){
                        ALLEGRO_EVENT ev;
                        al_wait_for_event(event_queue, &ev);

                        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                            quit=true;
                            break;
                        }

                        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                            switch(ev.keyboard.keycode) {
                                case ALLEGRO_KEY_1: /* wybor poziomu 1*/
                                    p.wczytaj_plansze(0);
                                    if (graj(p, 0, display, event_queue, timer)!=1)
                                        wygrana(p, 0, display, event_queue, timer);
                                    poziom=true;
                                    break;

                                case ALLEGRO_KEY_2: /* wybor poziomu 2*/
                                    p.wczytaj_plansze(1);
                                    if (graj(p, 1, display, event_queue, timer)!=1);
                                        wygrana(p, 1, display, event_queue, timer);
                                    poziom=true;
                                    break;

                                case ALLEGRO_KEY_3: /* wybor poziomu 3*/
                                    p.wczytaj_plansze(2);
                                    if (graj(p, 2, display, event_queue, timer)!=1);
                                        wygrana(p, 2, display, event_queue, timer);
                                    poziom=true;
                                    break;

                            }
                        }
                    }

                break;
                }
            }
        }

    }

return 0;

}
