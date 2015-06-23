#include "clsPlansza.h"
#include "clsMenu.h"
#include "clsLudzik.h"
#include"clsSkrzynka.h"

/*
Floor	            (Space)     0
Wall	                #       1
Player	                @       2
Player on goal square	+       3
Box	                    $       4
Box on goal square	    *       5
Goal square	            .       6

 koniec levelu ;
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

};

void clsPlansza::WczytajDane()
{tblDane[0][0]='#';
tblDane[0][1]='#';
tblDane[0][2]='#';
tblDane[0][3]='#';
tblDane[0][4]='#';
tblDane[0][5]='#';
tblDane[0][6]='#';
tblDane[1][0]='#';
tblDane[1][1]=' ';
tblDane[1][2]=' ';
tblDane[1][3]=' ';
tblDane[1][4]=' ';
tblDane[1][5]='.';
tblDane[1][6]='#';
tblDane[2][0]='#';
tblDane[2][1]=' ';
tblDane[2][2]=' ';
tblDane[2][3]=' ';
tblDane[2][4]='$';
tblDane[2][5]=' ';
tblDane[2][6]='#';
tblDane[3][0]='#';
tblDane[3][1]=' ';
tblDane[3][2]='$';
tblDane[3][3]='@';
tblDane[3][4]='$';
tblDane[3][5]=' ';
tblDane[3][6]='#';
tblDane[4][0]='#';
tblDane[4][1]='.';
tblDane[4][2]='$';
tblDane[4][3]='$';
tblDane[4][4]=' ';
tblDane[4][5]='.';
tblDane[4][6]='#';
tblDane[5][0]='#';
tblDane[5][1]='.';
tblDane[5][2]='.';
tblDane[5][3]=' ';
tblDane[5][4]=' ';
tblDane[5][5]=' ';
tblDane[5][6]='#';
tblDane[6][0]='#';
tblDane[6][1]='#';
tblDane[6][2]='#';
tblDane[6][3]='#';
tblDane[6][4]='#';
tblDane[6][5]='#';
tblDane[6][6]='#';
}

void clsPlansza::WypiszDane()
{
    for(int i = 0; i < intWiersze ; i++)
    {   for(int j = 0; j < intKolumny; j++)
        {
            cout << tblDane[i][j];
        }
        cout << endl;
    }
}

void clsPlansza::KonwertujDane()
{
    cout << endl;
    cout << endl;

    for(int i = 0; i < intWiersze ; i++)
    {   for(int j = 0; j < intKolumny; j++)
        {   switch(tblDane[i][j])
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
            }
            cout << tblPodloga[i][j];
        }
        cout << endl;
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
    al_flip_display();
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
    al_flip_display();
}

