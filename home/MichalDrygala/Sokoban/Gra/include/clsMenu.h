#ifndef CLSMENU_H
#define CLSMENU_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include<allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>

#include<clsPlansza.h>

class clsMenu
{

public:
    void WyswietlKomunikat(ALLEGRO_FONT* font);

    //Ko�czy program na ��danie u�ytkownika
    //void WyswietlPlansze(int pintNumerPlanszy);

};

#endif // CLSMENU_H
