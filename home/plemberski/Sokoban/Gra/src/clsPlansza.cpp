#include "clsPlansza.h"
#include "clsMenu.h"
#include "clsLudzik.h"
#include"clsSkrzynka.h"

#include<string>
#include<iostream>
#include<sstream>
using namespace std;
/*
Floor	            (Space)     0
Wall	                #       1
Player	                @       2
Player on goal square	+       3
Box	                    $       4
Box on goal square	    *       5
Goal square	            .       6
puste                   7       7
*/

const string clsPlansza::plik_z_kafelkiem[liczba_kafelkow] =
{
    "kafelki/podloga.png",
    "kafelki/sciana.png",
    "kafelki/ludziki.png",
    "kafelki/ludzikiNaCelu.png",
    "kafelki/skrzynki.png",
    "kafelki/skrzynkiNaCelu.png",
    "kafelki/cel.png",
    "kafelki/puste.png"

};

char tblDane[5][12][12] =
{
{
                        {'7','7','7','7','7','7','7','7','7','7','7','7'},
                        {'7','7','7','7','7','7','7','7','7','7','7','7'},
                        {'7','7','#','#','#','#','#','#','#','7','7','7'},
                        {'7','7','#',' ',' ',' ',' ','.','#','7','7','7'},
                        {'7','7','#',' ',' ',' ','$',' ','#','7','7','7'},
                        {'7','7','#',' ','$','@','$',' ','#','7','7','7'},
                        {'7','7','#','.','$','$',' ','.','#','7','7','7'},
                        {'7','7','#','.','.',' ',' ',' ','#','7','7','7'},
                        {'7','7','#','#','#','#','#','#','#','7','7','7'},
                        {'7','7','7','7','7','7','7','7','7','7','7','7'},
                        {'7','7','7','7','7','7','7','7','7','7','7','7'},
                        {'7','7','7','7','7','7','7','7','7','7','7','7'},

},{
                        {'7','7','7','7','7','7','7','7','7','7','7','7'},
                        {'7','#','#','#','#','#','#','#','#','#','7','7'},
                        {'7','#','.',' ',' ','#',' ',' ','.','#','7','7'},
                        {'7','#',' ','#',' ',' ',' ','#',' ','#','7','7'},
                        {'7','#',' ',' ','#','$','#',' ',' ','#','7','7'},
                        {'7','#',' ',' ','$','@','$',' ',' ','#','7','7'},
                        {'7','#',' ',' ','#','$','#',' ',' ','#','7','7'},
                        {'7','#',' ','#',' ',' ',' ','#',' ','#','7','7'},
                        {'7','#','.',' ',' ','#',' ',' ','.','#','7','7'},
                        {'7','#','#','#','#','#','#','#','#','#','7','7'},
                        {'7','7','7','7','7','7','7','7','7','7','7','7'},
                        {'7','7','7','7','7','7','7','7','7','7','7','7'},
},{
                        {'7','7','7','7','7','7','7','7','7','7','7','7'},
                        {'7','7','7','7','#','#','#','#','7','7','7','7'},
                        {'7','#','#','#','#',' ',' ','#','#','7','7','7'},
                        {'7','#',' ',' ',' ','$',' ',' ','#','7','7','7'},
                        {'7','#',' ',' ','*','*','*',' ','#','7','7','7'},
                        {'7','#',' ',' ','.',' ','.',' ','#','#','7','7'},
                        {'7','#','#',' ','*',' ','*',' ',' ','#','7','7'},
                        {'7','7','#','#','*','*','*',' ',' ','#','7','7'},
                        {'7','7','7','#',' ','$',' ','#','#','#','7','7'},
                        {'7','7','7','#',' ','@',' ','#','7','7','7','7'},
                        {'7','7','7','#','#','#','#','#','7','7','7','7'},
                        {'7','7','7','7','7','7','7','7','7','7','7','7'},
},{
                        {'7','7','7','#','#','#','#','#','7','7','7','7'},
                        {'7','7','7','#',' ','.',' ','#','7','7','7','7'},
                        {'7','#','#','#','$',' ','$','#','#','#','7','7'},
                        {'7','#',' ',' ','$',' ','$',' ',' ','#','7','7'},
                        {'7','#',' ','.',' ','.',' ','.',' ','#','7','7'},
                        {'7','#','#','#',' ','*',' ','#','#','#','7','7'},
                        {'7','7','7','#',' ','*',' ','#','7','7','7','7'},
                        {'7','7','7','#','$','.','$','#','7','7','7','7'},
                        {'7','7','7','#',' ','.',' ','#','7','7','7','7'},
                        {'7','7','7','#','$','.','$','#','7','7','7','7'},
                        {'7','7','7','#',' ','+',' ','#','7','7','7','7'},
                        {'7','7','7','#','#','#','#','#','7','7','7','7'},
},{
                        {'7','7','7','#','#','#','#','#','7','7','7','7'},
                        {'7','#','#','#',' ',' ',' ','#','#','#','#','7'},
                        {'7','#',' ',' ',' ','$',' ','#',' ',' ','#','7'},
                        {'7','#',' ','@','.','.','.','#',' ',' ','#','#'},
                        {'#','#','#','#','$','$','$','$','.',' ',' ','#'},
                        {'#',' ',' ','.','$','.','.','$','.','$',' ','#'},
                        {'#',' ','$','.','$','.','.','$','.',' ',' ','#'},
                        {'#',' ',' ','.','$','$','$','$','#','#','#','#'},
                        {'#','#',' ',' ','#','.','.','.',' ',' ','#','7'},
                        {'7','#',' ',' ','#',' ','$',' ',' ',' ','#','7'},
                        {'7','#','#','#','#',' ',' ',' ','#','#','#','7'},
                        {'7','7','7','7','#','#','#','#','#','7','7','7'},
}
};

void clsPlansza::KonwertujDane()
{
    for(int i = 0; i < intWiersze ; i++)
    {   for(int j = 0; j < intKolumny; j++)
        {   switch(tblDane[level - 1][i][j])
            {   case ' ':
                    tblPodloga[i][j] = 0;
                    tblSkrzynkiP[i][j] = 0;
                    break;

                case '#':
                    tblPodloga[i][j] = 1;
                   tblSkrzynkiP[i][j] = 0;
                    break;

                case '@':
                    tblPodloga[i][j] = 0;
                    tblSkrzynkiP[i][j] = 0;
                    xLudzik = i;
                    yLudzik = j;
                    break;

                case '+':
                    tblPodloga[i][j] = 6;
                    tblSkrzynkiP[i][j] = 0;
                    xLudzik = i;
                    yLudzik = j;
                    break;

                case '$':
                    tblPodloga[i][j] = 0;
                    tblSkrzynkiP[i][j] = 1;
                    break;

                case '*':
                    tblPodloga[i][j] = 6;
                    tblSkrzynkiP[i][j] = 1;
                    break;

                case '.':
                    tblPodloga[i][j] = 6;
                    tblSkrzynkiP[i][j] = 0;
                    break;

                case '7':
                    tblPodloga[i][j] = 7;
                    tblSkrzynkiP[i][j] = 0;
                    break;
            }
        }
    }
}

bool clsPlansza::przygotuj_bitmapy()
{   for (int i = 0; i < liczba_kafelkow; i++)
        {   bitmapa[i] = al_load_bitmap(plik_z_kafelkiem[i].c_str());

            if (!bitmapa[i])
            {   cerr << "Blad podczas wczytywania bitmapy " << plik_z_kafelkiem[i] << "." << endl;
                return false;
            }
        }
    return true;
}

void clsPlansza::rysuj_statyczne()
{
    al_clear_to_color(al_map_rgb(0,0,0));

    for (int i = 0; i < intWiersze; i++)
    {   for (int j = 0; j < intKolumny; j++)
        {    al_draw_bitmap_region(bitmapa[tblPodloga[i][j]], 0, 0, k_sz, k_wy, intYStart + j * k_sz, intXStart + i * k_sz, 0);
        }
    }

    //al_flip_display();
}

void clsPlansza::rysuj_ruchome(clsLudzik l, clsSkrzynka s, int wersja)
{
    //rysuje czlowieczka
    if(tblPodloga[l.get_X()][l.get_Y()] == 0)//jesli stoi na podlodze
    {   al_draw_bitmap_region(bitmapa[2], 32 * wersja, 0, k_sz, k_wy, intYStart + l.get_Y() * k_sz, intXStart + l.get_X() * k_wy, 0);
    }
    else if(tblPodloga[l.get_X()][l.get_Y()] == 6)//jesli stoi na celu
    {   al_draw_bitmap_region(bitmapa[3], 32 * wersja, 0, k_sz, k_wy, intYStart + l.get_Y() * k_sz, intXStart + l.get_X() * k_wy, 0);
    }

    //rysuje skrzynki
     for (int i = 0; i < intWiersze; i++)
    {   for (int j = 0; j < intKolumny; j++)
        {    if (s.get_tblSkrzynkiS(i, j) == 1 )
            {   if(tblPodloga[i][j] == 0)//jesli stoi na podlodze
                {   al_draw_bitmap_region(bitmapa[4], 32 * wersja, 0, k_sz, k_wy, intYStart + j * k_sz, intXStart + i * k_sz, 0);
                }
                else if(tblPodloga[i][j] == 6)//jesli stoi na celu
                {   al_draw_bitmap_region(bitmapa[5], 32 * wersja, 0, k_sz, k_wy, intYStart + j * k_sz, intXStart + i * k_sz, 0);
                }
            }
        }
    }
    //al_flip_display();
}

    //ustala ze ukonczona plansze na ktora wlasnie wksazuje wskaznik oraz przesuwa wskaznik o jeden nizej
    void clsPlansza::set_tblUkonczone(bool wynik)
    {
        *wskTblUkonczone = wynik;
        wskTblUkonczone++;
    }

   void clsPlansza::WyswietlKomunikat(ALLEGRO_FONT* font, ALLEGRO_FONT* font2)
 {
    //string strLevel = to_string(level);
    //string strKomunikat = "LEVEL ";
    //strKomunikat += strLevel;
    stringstream sstm;
    sstm << "LEVEL " << level; // konwersja int na string
    string strKomunikat = sstm.str();
    const char *chrKomunikat = strKomunikat.c_str();    //przekonwertowanie stringa na chr

    al_draw_text( font, al_map_rgb(213, 173, 66), 120, 500, ALLEGRO_ALIGN_LEFT, chrKomunikat );

    strKomunikat = "Wcisnij klawisz:";
    const char *chrKomunikat2 = strKomunikat.c_str();
    al_draw_text( font2, al_map_rgb(213, 173, 66), 820, 200, ALLEGRO_ALIGN_LEFT, chrKomunikat2 );

    strKomunikat = "R - restart planszy";
    const char *chrKomunikat3 = strKomunikat.c_str();
    al_draw_text( font2, al_map_rgb(213, 173, 66), 820, 230, ALLEGRO_ALIGN_LEFT, chrKomunikat3 );

    strKomunikat = "M - powrot do MENU";
    const char *chrKomunikat4 = strKomunikat.c_str();
    al_draw_text( font2, al_map_rgb(213, 173, 66), 820, 260, ALLEGRO_ALIGN_LEFT, chrKomunikat4 );

    strKomunikat = "ESC - wyjscie z programu";
    const char *chrKomunikat5 = strKomunikat.c_str();
    al_draw_text( font2, al_map_rgb(213, 173, 66), 820, 290, ALLEGRO_ALIGN_LEFT, chrKomunikat5 );

    // al_flip_display();
 }
