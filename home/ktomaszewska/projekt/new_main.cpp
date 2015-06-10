#include <iostream>
#include "gra.h"
#include <cmath>
#include <windows.h>

using namespace std;

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


int main(int, char**){
    Gra *gra=new Gra; //(Plansza &p, Klocek &k);
    Klocek *k=new Klocek;
    Plansza *p=new Plansza;

    int s=20;
    int w=20;
    const float FPS=60.0;

    if (!al_init() || !al_install_keyboard() || !al_init_image_addon())
    {
        cout << "B³¹d inicjalizacji." << endl;
        return 1;
    }

    ALLEGRO_DISPLAY *display = al_create_display(s,w);
    ALLEGRO_TIMER *timer = al_create_timer(1.0/FPS);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

    if (display==NULL || timer==NULL || event_queue==NULL)
    {
        cout << "B³¹d inicjalizacji." << endl;
        return 2;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    ALLEGRO_BITMAP *menu = al_load_bitmap("menu.png");
    ALLEGRO_BITMAP *wyniki = al_load_bitmap("wyniki.png");
    ALLEGRO_BITMAP *poziom = al_load_bitmap("poziom.png");

    al_clear_to_color(al_map_rgb(0,0,0));

    al_draw_bitmap(menu,255,255,255);
    al_flip_display();

    al_start_timer(timer);

    while (true)
    {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if(event.type==ALLEGRO_EVENT_TIMER)
        {
            if (p->czy_kolizja(gra->pX,gra->pY,gra->typ_klocka, gra->rotacja_klocka)==0)
                gra->pY++;

            else
            {
                p->umiesc_klocek(gra->pX, gra->pY, gra->typ_klocka,gra->rotacja_klocka);
                p->usun_mozliwe_linie();
                if (p->czy_przegrana())
                    exit(0);
                gra->generuj_klocek();
            }
        }
        switch(event.keyboard.keycode)
        {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
            {
                break;
            }
//koniec
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
//wybory szybkosci
            case ALLEGRO_KEY_3:
            {
                FPS=FPS-20;
            }
            case ALLEGRO_KEY_2:
            {
                FPS=FPS-10;
            }
            case ALLEGRO_KEY_1:
            {
                FPS=FPS;
            }
//wybory zapelnienia
            case ALLEGRO_KEY_C:
            {
                p->zapelnij_plansze(3);
            }
            case ALLEGRO_KEY_B:
            {
                p->zapelnij_plansze(2);
            }
            case ALLEGRO_KEY_A:
            {
                p->zapelnij_plansze(1);
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
                while (p->czy_kolizja(gra->pX,gra->pY-1,gra->typ_klocka,gra->rotacja_klocka)==0)
                    gra->pY++;
                    p->umiesc_klocek(gra->pX, gra->pY-1,gra->typ_klocka, gra->rotacja_klocka);
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
    return 0;
}

