#include <iostream>
#include "gra.h"
#include <cmath>

using namespace std;

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

const float FPS=600.0;

int main(int, char**){
    Gra *gra=new Gra; //(Plansza &p, Klocek &k);
    gra -> rozpocznij_gre();

    Plansza *p=new Plansza;
    p -> k = new Klocek;

    float energia = 0.0;

    //int s=20;
    //int w=20;

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

   // all_init();
    al_init_primitives_addon();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    //al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    ALLEGRO_BITMAP *menu = al_load_bitmap("menu.png");
    ALLEGRO_BITMAP *wyniki = al_load_bitmap("wyniki.png");
    ALLEGRO_BITMAP *poziom = al_load_bitmap("poziom.png");
    ALLEGRO_BITMAP *plansza = al_load_bitmap("plansza.png");

    if (menu == NULL || wyniki == NULL || poziom == NULL) {
        cout << "Brak bitmapy." << endl;
        return 3;
    }

    al_clear_to_color(al_map_rgb(0,0,0));

    al_draw_bitmap(menu,0,0,0);
    al_flip_display();

    //al_start_timer(timer);

    int trudnosc = 0;
    int stan = 1;

    while (true) {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;
        else if (event.keyboard.keycode == ALLEGRO_KEY_K)
            break;

        if (stan == 1) {
            if(event.keyboard.keycode == ALLEGRO_KEY_S) {
//start
                al_draw_bitmap(poziom,0,0,0);
                al_flip_display();
                stan = 2;
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_N) {
                al_clear_to_color(al_map_rgb(255,255,255));
                al_draw_bitmap(wyniki,0,0,0);
                al_flip_display();
                stan = 4;
            }
        }
        else if (stan == 2) {
            if(event.keyboard.keycode == ALLEGRO_KEY_3)
                trudnosc = 2;
            else if (event.keyboard.keycode == ALLEGRO_KEY_2)
                trudnosc = 1;
            else if (event.keyboard.keycode == ALLEGRO_KEY_1)
                trudnosc = 0;
            else if (event.keyboard.keycode == ALLEGRO_KEY_C) {
                al_clear_to_color(al_map_rgb(255,255,255));
                al_draw_bitmap(plansza,0,0,0);
                p->zapelnij_plansze(3);
                p->rysuj_plansze();
                //al_draw_bitmap(plansza,0,0,0);
                al_flip_display();
                stan = 3;

            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_B) {
                al_clear_to_color(al_map_rgb(255,255,255));
                al_draw_bitmap(plansza,0,0,0);
                p->zapelnij_plansze(2);
                p->rysuj_plansze();
//                al_draw_bitmap(plansza,0,0,0);
                al_flip_display();
                stan = 3;
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_A) {
                al_clear_to_color(al_map_rgb(255,255,255));
                al_draw_bitmap(plansza,0,0,0);
                p->zapelnij_plansze(1);
                p->rysuj_plansze();
//                al_draw_bitmap(plansza,0,0,0);
                al_flip_display();
                stan = 3;
            }
        }

        else if (stan == 3) {
            al_register_event_source(event_queue, al_get_timer_event_source(timer));
            al_start_timer(timer);
            p->rysuj_plansze();
            cout << gra->pX << " " << gra->pY << " " << gra->typ_klocka << " " << gra->rotacja_klocka << endl;
            gra->rysuj_klocek(gra->pX, gra->pY, gra->typ_klocka, gra->rotacja_klocka);
            //gra->rysuj_klocek(gra->n_pX, gra->n_pY, gra->n_typ_klocka, gra->n_rotacja_klocka);
            al_flip_display();
            if(event.type==ALLEGRO_EVENT_TIMER) {
                switch (trudnosc) {
                    case 0: energia += 0.5; break;
                    case 1: energia += 1.5; break;
                    case 2: energia += 2.0; break;
                }

            cout << "TIMER" << endl;

            if (energia > 100) {
                if (p->czy_kolizja(gra->pX,gra->pY+1,gra->typ_klocka, gra->rotacja_klocka)==0) {
                    gra->pY++;
                    //p->umiesc_klocek(gra->pX, gra->pY, gra->typ_klocka, gra->rotacja_klocka);
                    //p->rysuj_plansze();
                    //al_flip_display();
                    }
                else {
                    p->umiesc_klocek(gra->pX, gra->pY, gra->typ_klocka, gra->rotacja_klocka);
                    p->usun_mozliwe_linie();
                    if (p->czy_przegrana())
                        exit(0);
                    //p->rysuj_plansze();
                    //al_flip_display();
                    gra->generuj_klocek();
                    //gra->rysuj_klocek(gra->n_pX, gra->n_pY, gra->n_typ_klocka, gra->n_rotacja_klocka);

                }
                energia = 0.0;
            }
        }

        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (event.keyboard.keycode == ALLEGRO_KEY_DOWN) {
// ruch strz³kami
                    while (p->czy_kolizja(gra->pX,gra->pY+1,gra->typ_klocka,gra->rotacja_klocka)==0)
                        gra->pY++;
                        p->umiesc_klocek(gra->pX, gra->pY,gra->typ_klocka, gra->rotacja_klocka);
                        p->usun_mozliwe_linie();
                        if (p->czy_przegrana())
                            exit(0);
                        gra->generuj_klocek();
                        //gra->rysuj_klocek(gra->n_pX, gra->n_pY, gra->n_typ_klocka, gra->n_rotacja_klocka);

                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_UP) {
                    if(p->czy_kolizja(gra->pX,gra->pY,gra->typ_klocka, gra->rotacja_klocka+1)==0)
                        gra->rotacja_klocka=(gra->rotacja_klocka+1)%4;
                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
                    if(p->czy_kolizja(gra->pX-1,gra->pY,gra->typ_klocka, gra->rotacja_klocka)==0)
                        gra->pX--;
                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
                    if(p->czy_kolizja(gra->pX+1,gra->pY,gra->typ_klocka, gra->rotacja_klocka)==0)
                        gra->pX++;
                }
            }
        }
    }
    return 0;
}

