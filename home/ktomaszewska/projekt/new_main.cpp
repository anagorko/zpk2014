#include <iostream>
#include "gra.h"
#include <cmath>

using namespace std;

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

const float FPS=60.0;

int main(int, char**){
    Gra *gra=new Gra; //(Plansza &p, Klocek &k);
    gra -> rozpocznij_gre();
    
    Plansza *p=new Plansza;
    p -> k = new Klocek;
    
    float energia = 0.0;
    
    int s=20;
    int w=20;

    if (!al_init() || !al_install_keyboard() || !al_init_image_addon())
    {
        cout << "Blad inicjalizacji." << endl;
        return 1;
    }

    ALLEGRO_DISPLAY *display = al_create_display(800,600);
    ALLEGRO_TIMER *timer = al_create_timer(1.0/FPS);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

    if (display==NULL || timer==NULL || event_queue==NULL)
    {
        cout << "Blad inicjalizacji." << endl;
        return 2;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    ALLEGRO_BITMAP *menu = al_load_bitmap("menu.png");
    ALLEGRO_BITMAP *wyniki = al_load_bitmap("wyniki.png");
    ALLEGRO_BITMAP *poziom = al_load_bitmap("poziom.png");
//    ALLEGRO_BITMAP *plansza = al_load_bitmap("plansza.png");

    if (menu == NULL || wyniki == NULL || poziom == NULL) {
        cout << "Brak bitmapy." << endl;
        return 3;
    }
    
    al_clear_to_color(al_map_rgb(0,0,0));

    al_draw_bitmap(menu,255,255,255);
    al_flip_display();

    al_start_timer(timer);

    int trudnosc = 0;
    
    while (true)
    {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if(event.type==ALLEGRO_EVENT_TIMER)
        {
            switch (trudnosc) {
            case 0: energia += 1.0; break;
            case 1: energia += 1.5; break;
            case 2: energia += 2.0; break;
            }
            
            cout << "TIMER" << endl;
            
            if (energia > 100) {
                if (p->czy_kolizja(gra->pX,gra->pY+1,gra->typ_klocka, gra->rotacja_klocka)==0) {
                    gra->pY++;
                    p->umiesc_klocek(gra->pX, gra->pY, gra->typ_klocka,gra->rotacja_klocka);
                    }
                else
                    {
                    p->umiesc_klocek(gra->pX, gra->pY, gra->typ_klocka,gra->rotacja_klocka);
                    p->usun_mozliwe_linie();
                    if (p->czy_przegrana())
                        exit(0);

                    gra->generuj_klocek();
                }
                energia = 0.0;
            }
        }
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }
        
        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
        switch(event.keyboard.keycode)
        {
            case ALLEGRO_KEY_K:
            {
                break;
            }
//start
            case ALLEGRO_KEY_S:
            {
                al_draw_bitmap(poziom,0,0,0);
                al_flip_display();
            }
                break;
//wybory szybkosci
            case ALLEGRO_KEY_3:
            {
                trudnosc = 2; break;
            }
            case ALLEGRO_KEY_2:
            {
                trudnosc = 1; break;
            }
            case ALLEGRO_KEY_1:
            {
                trudnosc = 0; break;
            }
//wybory zapelnienia
            case ALLEGRO_KEY_C:
            {
                p->zapelnij_plansze(3);
// DO NAPISANIA:                rysuj_plansze(p);
//                al_draw_bitmap(plansza,0,0,0);
                al_flip_display();
            }
            case ALLEGRO_KEY_B:
            {
                p->zapelnij_plansze(2);
//                al_draw_bitmap(plansza,0,0,0);
                al_flip_display();
            }
            case ALLEGRO_KEY_A:
            {
                p->zapelnij_plansze(1);
//                al_draw_bitmap(plansza,0,0,0);
                al_flip_display();
            }
//najlepszy wynik
            case ALLEGRO_KEY_N:
            {
                al_clear_to_color(al_map_rgb(255,255,255));
                al_draw_bitmap(wyniki,0,0,0);
                al_flip_display();
            }
// ruch strz³kami
            case ALLEGRO_KEY_DOWN:
            {
                while (p->czy_kolizja(gra->pX,gra->pY+1,gra->typ_klocka,gra->rotacja_klocka)==0)
                    gra->pY++;
                    p->umiesc_klocek(gra->pX, gra->pY,gra->typ_klocka, gra->rotacja_klocka);
                    p->usun_mozliwe_linie();
                    if (p->czy_przegrana())
                        exit(0);
                    gra->generuj_klocek();
                break;
            }
            case  ALLEGRO_KEY_UP:
            {
                if(p->czy_kolizja(gra->pX,gra->pY,gra->typ_klocka, gra->rotacja_klocka+1)==0)
                    gra->rotacja_klocka=(gra->rotacja_klocka+1)%4;
                break;
            }
            case  ALLEGRO_KEY_LEFT:
            {
                if(p->czy_kolizja(gra->pX-1,gra->pY,gra->typ_klocka, gra->rotacja_klocka)==0)
                    gra->pX--;
                break;
            }
            case  ALLEGRO_KEY_RIGHT:
            {
                if(p->czy_kolizja(gra->pX+1,gra->pY,gra->typ_klocka, gra->rotacja_klocka)==0)
                    gra->pX++;
                break;
            }
        }
        }
    }
    return 0;
}

