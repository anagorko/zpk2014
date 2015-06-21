#include "clsMenu.h"

#include <string>
using namespace std;

    void clsMenu::WyswietlKomunikat(ALLEGRO_FONT* font)
 {
    string strKomunikat = "asd";
    const char *chrKomunikat = strKomunikat.c_str();    //przekonwertowanie stringa na chr

     al_draw_text( font, al_map_rgb(0,0,255), 120, 116, ALLEGRO_ALIGN_CENTRE, chrKomunikat );
     al_flip_display();
 }
