#include "klocek.h"


// do wyrzucenia, bo nie jest potrzebne
int  Klocek::klocek_piksel(int typ_klocka, int rotacja_klocka, int X, int Y){
     return klocki[typ_klocka][rotacja_klocka][X][Y];
}

bool Klocek::czy_pusty_wiersz(int typ_klocka, int rotacja_klocka, int wiersz){
    for (int i=0;i<5;i++)
    {
        if (klocki[typ_klocka][rotacja_klocka][wiersz][i]!=0)
            return 0;
    }
    return 1;
}
