#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

#include<allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>


const int screen_w = 1440;
const int screen_h = 810;
const float FPS = 60.0;
bool quit=false;


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

int x;
int y;
int energia;


class Plansza
{
 int p[9][16];
 int o[9][16];

public:
    void wczytaj_plansze(int numer_poziomu)
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

    void wykonajRuch(int kierunek, int &energia){  // 0 - gora; 1 - prawo; 2 - dol; 3 - lewo
        if (energia<10)
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



    bool czyKoniec(){
        for (int i=0; i<16; i++){
            for (int j=0; j<9; j++){
                if (podloga(j,i)==1 && obiekt(j,i)!=2)
                    return false;
            }
        }
        return true;
    }

};

int rysuj_plansze(Plansza &p){

    // tworzenie wskaznikow do elementow planszy

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


    // wczytanie elementow planszy
    sciana = al_load_bitmap("sciana.png");
    pole = al_load_bitmap("pole.png");
    bambus = al_load_bitmap("bambus.png");
    magazyn = al_load_bitmap("magazyn.png");
    panda = al_load_bitmap("panda.png");

    // sprawdzenie czy elementy sie wczytaly
    if(!pole || !sciana || !bambus || !magazyn) {
        return 1;
    }

    // koloruje okno na czarno
    al_clear_to_color(al_map_rgb(0,0,0));

    // rysuje elementy planszy
    for (int j=0; j<9; j++){
        for (int i=0; i<16; i++){
            if (p.obiekt(j,i) ==1 && p.podloga(j,i) ==0)
                al_draw_bitmap(sciana,i*90,j*90,0);
            else if (p.obiekt(j,i)==0 && p.podloga(j,i)==0)
                al_draw_bitmap(pole,i*90,j*90,0);
            else if (p.obiekt(j,i)==2 && p.podloga(j,i)==0)
                al_draw_bitmap(bambus,i*90,j*90,0);
            else if (p.obiekt(j,i)==3)
                al_draw_bitmap(panda,i*90,j*90,0);
            else if (p.podloga(j,i)==1 && p.obiekt(j,i)==0)
                al_draw_bitmap(magazyn,i*90,j*90,0);
            else if (p.podloga(j,i)==1 && p.obiekt(j,i)==2)
                al_draw_bitmap(bambus,i*90,j*90,0);
        }
    }

    // wyswietla plansze
    al_flip_display();

    // usuwa wksazniki
    al_destroy_bitmap(sciana);
    al_destroy_bitmap(pole);
    al_destroy_bitmap(bambus);
    al_destroy_bitmap(magazyn);
    al_destroy_bitmap(panda);

    return 0;

}

int ekran_powitalny(Plansza &p){

    ALLEGRO_BITMAP  *menu   = NULL;
    // sprawdzenie inicjalizacji allegro
    if(!al_init()) {
        return 1;
    }

    if(!al_init_image_addon()) {
        return 1;
    }

    // wczytanie elementow planszy
    menu = al_load_bitmap("menu.png");

    // sprawdzenie czy elementy sie wczytaly
    if(!menu) {
        return 1;
    }

    al_draw_bitmap(menu,0,0,0);

    // wyswietla plansze
    al_flip_display();

    // usuwa wksazniki
    al_destroy_bitmap(menu);

    return 0;
}

int ekran_poziomy(Plansza &p){

    ALLEGRO_BITMAP  *poziomy   = NULL;
    // sprawdzenie inicjalizacji allegro
    if(!al_init()) {
        return 1;
    }

    if(!al_init_image_addon()) {
        return 1;
    }

    // wczytanie elementow planszy
    poziomy = al_load_bitmap("poziomy.png");

    // sprawdzenie czy elementy sie wczytaly
    if(!poziomy) {
        return 1;
    }

    al_draw_bitmap(poziomy,0,0,0);

    // wyswietla plansze
    al_flip_display();

    // usuwa wksazniki
    al_destroy_bitmap(poziomy);

    return 0;
}

int graj(Plansza &p, int poziom){

    ALLEGRO_DISPLAY *display = al_create_display(screen_w, screen_h);
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

    if (display == NULL || timer == NULL || event_queue == NULL) {
        cout << "Błąd inicjalizacji." << endl;
        return 2;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_start_timer(timer);

    while (p.czyKoniec()==false){

        // kolejka zdarzeń
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER) {
            energia=energia+1;
        }

        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            quit=true;
            break;
        }

        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    p.wykonajRuch(0,energia);
                    break;
                case ALLEGRO_KEY_LEFT:
                    p.wykonajRuch(3,energia);
                    break;
                case ALLEGRO_KEY_RIGHT:
                    p.wykonajRuch(1,energia);
                    break;
                case ALLEGRO_KEY_DOWN:
                    p.wykonajRuch(2,energia);
                    break;
                case ALLEGRO_KEY_R:
                    p.wczytaj_plansze(poziom);
                    break;
                case ALLEGRO_KEY_W:
                    quit=true;
                    return 0;
                    break;
            }
        }


        // rysowanie planszy
        rysuj_plansze(p);
    };
    quit=true;

}


int main(int, char**){

    Plansza p; // stworzenie planszy

    if (!al_init() || !al_install_keyboard() || !al_init_image_addon()) {
            cout << "Błąd inicjalizacji." << endl;
            return 1;
    }

    ALLEGRO_DISPLAY *display = al_create_display(screen_w, screen_h);
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

    if (display == NULL || timer == NULL || event_queue == NULL) {
        cout << "Błąd inicjalizacji." << endl;
        return 2;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    ekran_powitalny(p);
    al_flip_display();

    while (quit==false){

        // kolejka zdarzeń
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                break;
        }

        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_W:
                    quit=true;
                    break;

                case ALLEGRO_KEY_G:
                {
                    ekran_poziomy(p);

                    ALLEGRO_EVENT_QUEUE *event_queue1 = al_create_event_queue();

                    al_register_event_source(event_queue1, al_get_display_event_source(display));
                    al_register_event_source(event_queue1, al_get_keyboard_event_source());

                    bool poziom=false;

                    while (poziom==false){
                        ALLEGRO_EVENT ev1;
                        al_wait_for_event(event_queue1, &ev1);

                        if(ev1.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                            quit=true;
                            break;
                        }

                        else if(ev1.type == ALLEGRO_EVENT_KEY_DOWN) {
                            switch(ev1.keyboard.keycode) {
                                case ALLEGRO_KEY_1:
                                    p.wczytaj_plansze(0); // wczytanie planszy
                                    graj(p, 0);
                                    poziom=true;
                                    break;

                                case ALLEGRO_KEY_2:
                                    p.wczytaj_plansze(1); // wczytanie planszy
                                    graj(p, 1);
                                    poziom=true;
                                    break;

                                case ALLEGRO_KEY_3:
                                    p.wczytaj_plansze(2); // wczytanie planszy
                                    graj(p, 2);
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


}

