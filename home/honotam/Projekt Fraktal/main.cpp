/* ***************************************************************************** */
/*     Projekt na zaliczenie przedmiotu Zaawansowane programowanie komputerowe   */
/*                                                                               */
/*                          "Fraktal Mandelbrota"                                */
/*                                                                               */
/*                            Helena Kleczynska                                  */
/* *******************************************************************************/


using namespace std;
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "okna.h"
#include "fraktal.h"

int main()
{
    Fraktal *rys  = new Fraktal();

    const float FPS = 60.0;
    const int iteracje_maks = 200;
    double _x;
    double _y;
    const int wysokosc = 600;
    const int szerokosc = 1000;

    if ( !al_init() || !al_install_keyboard() || !al_init_primitives_addon() || !al_install_mouse())
    {
        cout << "Blad inicjalizacji" << endl;
        return 1;
    }

    al_init_font_addon();
    al_init_ttf_addon();    // odczytywanie czcionki
    al_init_image_addon();  // odczytywanie plików graficznych

    ALLEGRO_DISPLAY *display = al_create_display(szerokosc, wysokosc);
    al_set_window_title( display,"Fraktal Mandelbrota");
    al_set_display_icon( display, al_load_bitmap("images\\ikona.png"));
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
    al_start_timer( timer );
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

    if (display == NULL || timer == NULL || event_queue == NULL)
    {
        cout << "Blad inicjalizacji" << endl;
        return 2;
    }

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    al_clear_to_color(al_map_rgb(0, 0, 0));

    cout << "Finished init, starts drawing Fractal..." << endl;

    while (true)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            cout << "Punkty na bitmapie: x = " << ev.mouse.x << ", y = " << ev.mouse.y << endl;
            double k = 1;
            double x = ev.mouse.x;
            double y = ev.mouse.y;

            // wywolanie metody setScale
            rys->setScale(x, y);
            k++;
            cout << "Powiększenie " << k << endl;

            // wywolanie metody setZoom
            rys->setZoom(k);
            // wywolanie metody setPointX
            rys->setPointX(x);
            // wywolanie metody setPointY
            rys->setPointY(y);
            cout << "Koniec powiększania" << endl;
        }

        if (al_is_event_queue_empty(event_queue))
        {
                        for (_y = -296; _y < 298 ; ++_y)
            {
                for (_x = -346; _x < 348; ++_x)
                {
                        al_clear_to_color(al_map_rgb(0,0,0));
                }
            }

    // Ramka na statystyki
    al_set_clipping_rectangle(700, 260, 297, 337);
    al_clear_to_color(al_map_rgb(21, 3, 26));
    al_set_clipping_rectangle(0, 0, 1000, 600);

    // Ramka w której bêdzie okreslane po³ozenie powiekszenia wzgledem calego rysunku
    al_draw_bitmap(al_load_bitmap("images\\podglad.png"), 700, 3, 0);
    al_draw_bitmap(al_load_bitmap("images\\icon-map-pointer.png"), 846.5-12.5, 130-25, 0);

    // wywolanie metody Statystyki
    rys->Statystyki();
            double k = 0;

            for (_y = -296; _y < 298 ; ++_y)
            {
                for (_x = -346; _x < 348; ++_x)
                {
                    k = rys->kolor(_x, _y);
                    if (k > 0)
                    {
                        al_draw_pixel(_x + 700/2,_y + 600/2, al_map_rgb(k * 181 / iteracje_maks, k * 107 / iteracje_maks, k * 255 / iteracje_maks));
                    }
                }
            }

            cout << "Calculated and set pixels, refreshing...";
            cout << " Refreshed.\n";
            cout << "Rozmiary: " << rys->getXmin() << ", " << rys->getYmin() << ", " << rys->getXmax() << ", " << rys->getYmax() << endl;
            al_flip_display();
        }
    }
	return 0;

    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
}
