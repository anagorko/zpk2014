#include klocek.h

 int  Klocek::klocek_piksel(int typ_klocka, int rotacja_klocka, int pX, int pY)
 {
     return klocki[typ_klocka][rotacja_klocka][pX][pY];
 }


 bool Klocek::czy_pusty_wiersz((int typ_klocka, int rotacja_klocka, wiersz)
    {
        for (int i=0;i<5;i++)
           if ( klocki[typ_klocka][rotacja_klocka][wiersz][i]!=0){ return 0;}
        return 1;

    }
