#include "clsMenu.h"

#include <string>
using namespace std;

    void clsMenu::WyswietlKomunikat(ALLEGRO_FONT* font)
 {
    string strKomunikat = "Witamy!!!!";
    const char *chrKomunikat = strKomunikat.c_str();    //przekonwertowanie stringa na chr

     al_draw_text( font, al_map_rgb(0,0,255), 120, 316, ALLEGRO_ALIGN_CENTRE, chrKomunikat );
     al_flip_display();
 }

const string clsMenu::plik_z_menu[1]=
{
    "kafelki/menu.png"
};

void clsMenu::WyswietlMenu()
{
    ALLEGRO_BITMAP* wskMenu[1];

wskMenu[0] = al_load_bitmap(plik_z_menu[0].c_str());

al_clear_to_color(al_map_rgb(0,0,0));

al_draw_bitmap_region(wskMenu[0], 0, 0, 1240, 600, 0, 0, 0);

             al_flip_display();
}


