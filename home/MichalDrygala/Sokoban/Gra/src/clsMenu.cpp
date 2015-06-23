#include "clsMenu.h"

#include <string>
using namespace std;

    void clsMenu::WyswietlKomunikat(ALLEGRO_FONT* font)
 {
    string strKomunikat = "Witamy!!!!";
    const char *chrKomunikat = strKomunikat.c_str();    //przekonwertowanie stringa na chr

     al_draw_text( font, al_map_rgb(0,0,255), 120, 116, ALLEGRO_ALIGN_CENTRE, chrKomunikat );
     al_flip_display();
 }


/*

 string plik_z_kafelkiem[i] =    "kafelki/podloga.png",

 bitmapa[i] = al_load_bitmap(plik_z_kafelkiem[i].c_str());
 if (!bitmapa[i])
            {   cerr << "Blad podczas wczytywania bitmapy " << plik_z_kafelkiem[i] << "." << endl;
                return false;
            }

al_draw_bitmap_region(bitmapa[3], 0, 0, k_sz, k_wy, intYStart, intXStart, 0);
*/
