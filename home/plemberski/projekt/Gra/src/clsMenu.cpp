#include "clsMenu.h"

#include <string>
using namespace std;

    void clsMenu::WyswietlKomunikat(ALLEGRO_FONT* font)
 {
    string strKomunikat = "Wybierz cyfre 1 lub 2 by wybra� poziom:";
    const char *chrKomunikat = strKomunikat.c_str();    //przekonwertowanie stringa na chr

     al_draw_text( font, al_map_rgb(0,0,255), 120, 116, ALLEGRO_ALIGN_CENTRE, chrKomunikat );
     al_flip_display();
 }
