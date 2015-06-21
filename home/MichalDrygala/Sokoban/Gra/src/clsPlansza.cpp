#include "clsPlansza.h"
#include "clsMenu.h"

/*
Wall	                #
Player	            @
Player on goal square	+
Box	                $
Box on goal square	*
Goal square	        .
Floor	            (Space)
 koniec levelu ;

################
#   #######    #
# #   ...## $$$##
# ##  . .   $@$ #
# ## #...## $$$ #
#    ######     #
#################

*/

void clsPlansza::WczytajDane()
{

}

bool clsPlansza::przygotuj_bitmapy()
{   ALLEGRO_BITMAP* bitmapa[liczba_kafelkow];

    for (int i = 0; i < liczba_kafelkow; i++)
        {   bitmapa[i] = al_load_bitmap(plik_z_kafelkiem[i].c_str());

            if (!bitmapa[i])
            {   cerr << "Blad podczas wczytywania bitmapy " << plik_z_kafelkiem[i] << "." << endl;
                return false;
            }
        }
    return true;
}

void clsPlansza::przygotuj_plansze()
{   for (int i = 0; i < sz; i++)
    {   for (int j = 0; j < wy; j++)
        {   tblKefelki[i][j] = podloga;
        }
    }
}

void clsPlansza::rysuj_plansze()
{
    al_clear_to_color(al_map_rgb(0,0,0));

    for (int i = 0; i < sz; i++)
    {   for (int j = 0; j < wy; j++)
        {cout << "e" << endl;
            // najpierw podloga
            al_draw_bitmap_region(bitmapa[1], 0, 0, 10, 10, 0, 0, 0);
            //al_draw_bitmap_region(bitmapa[tblKefelki[i][j]], tblKefelki[i][j], 0, k_sz, k_wy, i*k_sz, j*k_sz, 0);
            cout << "f" << endl;
            al_flip_display();
        }
    }
}
