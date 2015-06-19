#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

const int screen_w = 800;
const int screen_h = 600;



int main(int, char**)
{
    if (!al_init() || !al_install_keyboard() || !al_init_image_addon()) {
        cout << "Blad inicjalizacji." << endl;
        return 1;
    }

    ALLEGRO_DISPLAY *display = al_create_display(screen_w, screen_h);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();//kolejka zdarzen

    if (display == NULL || event_queue == NULL) {
        cout << "Blad inicjalizacji." << endl;
        return 2;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());


    int mode = 0; //0 - wyswietlam ekran gry 1 - wyswietlam menu 2 - wyswietlam wyniki

    ALLEGRO_BITMAP * ekran_glowny = al_load_bitmap("ekran_glowny.png");
    ALLEGRO_BITMAP * menu = al_load_bitmap("menu.png");
    ALLEGRO_BITMAP * tablica_wynikow = al_load_bitmap("tablica_wynikow.png");

    al_clear_to_color(al_map_rgb(0,0,0));

    al_draw_bitmap(ekran_glowny,0,0,0);
    al_flip_display();




    while (true)
    {
        // process events
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);


        if( mode == 0 ){

            al_draw_bitmap(ekran_glowny,0,0,0);
            al_flip_display();

            if(ev.keyboard.keycode == ALLEGRO_KEY_DOWN) {
                    // w tym miejscu nalezy umiescic mechanike gry gdy naciskamy klawisz w dol
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_UP) {
                    // mechanika cd
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_RIGHT){
                    // mechanika w prawo

            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_LEFT){
                    // mechanika w lewo
            }

            // narazie wstepnie proponuje przejscie pomiedzy ekranami za pomoca wciskania przyciskow na klawiaturze
            // za pomoca klikniecia 'o' przechodzimy z ekranu glownego do menu
            else if(ev.keyboard.keycode == ALLEGRO_KEY_O){
                mode = 1;
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_Q){//wyjscie z gry moze nastapic w kazdym ekranie za pomoca 'q'
                break;
            }


        }

        else if ( mode == 1 ){
            al_draw_bitmap(menu,0,0,0);
            al_flip_display();


            if(ev.keyboard.keycode == ALLEGRO_KEY_W){//przejscie z menu do ekranu wynikow za pomoca wcisniecia przycisku 'w'
                mode = 2;
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_G){//przejscie do ekranu gry za pomoca przycisku 'g'
                mode = 0;
            }
            else if(ev.keyboard.keycode == ALLEGRO_KEY_Q){//wyjscie z gry moze nastapic w kazdym ekranie za pomoca 'q'
                break;
            }
        }

        else if ( mode == 2 ){
                al_draw_bitmap(tablica_wynikow,0,0,0);
                al_flip_display();

                if(ev.keyboard.keycode == ALLEGRO_KEY_O){//powrot z wynikow do menu za pomoca przycisku 'o'
                mode = 1;
                }
                else if(ev.keyboard.keycode == ALLEGRO_KEY_Q){//wyjscie z gry moze nastapic w kazdym ekranie za pomoca 'q'
                break;
                }



        }



    };

    return 0;
}
