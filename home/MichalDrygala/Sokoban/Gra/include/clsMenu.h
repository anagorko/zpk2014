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

    //Koñczy program na ¿¹danie u¿ytkownika
    //void WyswietlPlansze(int pintNumerPlanszy);

};

#endif // CLSMENU_H
