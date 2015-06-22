#include "clsPlansza.h"
#include "clsMenu.h"
#include "clsLudzik.h"

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
    "kafelki/ludzik.png",
    "kafelki/ludzikNaCelu.png",
    "kafelki/skrzynka.png",
    "kafelki/skrzynkaNaCelu.png",
    "kafelki/cel.png"
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
tblDane[1][1]='.';
tblDane[1][2]=' ';
tblDane[1][3]=' ';
tblDane[1][4]=' ';
tblDane[1][5]='.';
tblDane[1][6]='#';
tblDane[2][0]='#';
tblDane[2][1]=' ';
tblDane[2][2]='$';
tblDane[2][3]='$';
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
tblDane[4][4]='$';
tblDane[4][5]='.';
tblDane[4][6]='#';
tblDane[5][0]='#';
tblDane[5][1]='.';
tblDane[5][2]='.';
tblDane[5][3]=' ';
tblDane[5][4]='.';
tblDane[5][5]='.';
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
                    tblDaneLiczby[i][j] = 0;
                    break;

                case '#':
                    tblDaneLiczby[i][j] = 1;
                    break;

                case '@':
                    tblDaneLiczby[i][j] = 2;
                    break;

                case '+':
                    tblDaneLiczby[i][j] = 3;
                    break;

                case '$':
                    tblDaneLiczby[i][j] = 4;
                    break;

                case '*':
                    tblDaneLiczby[i][j] = 5;
                    break;

                case '.':
                    tblDaneLiczby[i][j] = 6;
                    break;
            }
            cout << tblDaneLiczby[i][j];
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

void clsPlansza::rysuj_plansze()
{
    al_clear_to_color(al_map_rgb(0,0,0));

    /*for (int i = 0; i < sz; i++)
    {   for (int j = 0; j < wy; j++)*/
    for (int i = 0; i < intWiersze; i++)
    {   for (int j = 0; j < intKolumny; j++)
        {
            al_draw_bitmap_region(bitmapa[tblDaneLiczby[i][j]], 1, 0, k_sz, k_wy, i * k_sz, j * k_sz, 0);
             al_flip_display();
        }
    }
}

    int clsPlansza::PozycjaLudzikaWiersz()
{
    for (int i = 0; i < intWiersze; i++)
    {   for (int j = 0; j < intKolumny; j++)
        {
            if (tblDaneLiczby[i][j] == 2) {return i;}
        }
    }
    cout << "Blad przy wyszukiwaniu pozycji Ludzika - wiersz";
    return -1;
}

    int clsPlansza::PozycjaLudzikaKolumna()
{
    for (int i = 0; i < intWiersze; i++)
    {   for (int j = 0; j < intKolumny; j++)
        {
            if (tblDaneLiczby[i][j] == 2) {return j;}
        }
    }
    cout << "Blad przy wyszukiwaniu pozycji Ludzika - kolumna";
    return -1;
}

