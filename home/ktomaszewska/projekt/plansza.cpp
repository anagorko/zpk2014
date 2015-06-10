#include "plansza.h"

int Plansza::losuj_liczbee(int a, int b){

return rand()%(b-a+1)+a;

}



void Plansza::pusta_plansza(){
     for (int i=0;i<wysokosc;i++)
     {
       for (int j=0;j<szerokosc;j++)
            tablica [i][j]=0;
     }
}

//do zmiany, w zaleznosci od poziomu gry
void Plansza::zapelnij_plansze(int level){
    int w;
    int k;
    if (level==2)
    {
        for (int i=1;i<11;i++)
        {
            w=losuj_liczbee(20,14);
            k=losuj_liczbee(0,10);
            if (tablica[w][k]==1)
                i--;
            else
                tablica[w][k]=1;
        }
    }
    else if (level==3)
    {
        for (int i=1;i<20;i++)
        {
            w=losuj_liczbee(20,14);
            k=losuj_liczbee(0,10);
            if (tablica[w][k]==1)
                i--;
            else
                tablica[w][k]=1;
        }
    }
}

bool Plansza::czy_kolizja(int pX, int pY, int typ_klocka, int rotacja_klocka){
    for (int i1=pX,i2=0;i1<pX+5;i1++,i2++)
    {
        for (int j1=pY,j2=0;j1<pY+5;j1++,j2++)
        {
            // czy klocek wychodzi poza plansze
            if (i1<0 || i1>szerokosc-1 || j1>wysokosc-1)
            {
                    if (k->klocki[typ_klocka][rotacja_klocka][i2][j2] !=0)
                    return 1;
            }
            // czy klocek nachodzi na inny juz na planszy
            if (j1>=0)
            {
                if (k->klocki[typ_klocka][rotacja_klocka][i2][j2] !=0 && tablica[i1][j1]!=0 )
                    return 1;
            }
        }
    }
    // brak kolizji
    return 0;
}

void Plansza::usun_linie(int wiersz){
        for (int i=0;i<szerokosc;i++)
            tablica[wiersz][i]=0;
        punkty++;

        for (int j=0;j<szerokosc;j++)
        {
            for (int k=wiersz-1;k>=0;k--)
                tablica[k+1][j]=tablica[k][j];
        }
}

void Plansza::usun_mozliwe_linie(){
    for (int j=0;j<20;j++)
    {
        int i=0;
        while (i<10)
        {
            if (tablica[i][j]=0)
                break;
            i++;
        }
        if (i==10)
            usun_linie (j);
    }
}

bool Plansza::czy_cala_linia(int wiersz){
        for (int i=0;i<szerokosc;i++)
        {
            if (tablica[wiersz][i]==0)
                return 0;
        }
        return 1;
}

bool Plansza::czy_koniec_poziomu(int poziom){
        if (poziom==1 and punkty>1000)
            return true;
        else if (poziom==2 and punkty>2000)
            return true;
        else if (poziom==3 and punkty>3000)
            return true;
        else
            return false;
}

bool Plansza::czy_przegrana(){
    for (int i=0;i<szerokosc;i++)
    {
        if (tablica[i][0]==1)
            return true;
    }
    return false;
}

void Plansza::umiesc_klocek(int pX, int pY, int typ_klocka,int rotacja_klocka){
    for (int i1=pX,i2=0;i1<pX+5;i1++,i2++)
    {
        for (int j1=pY,j2=0;j1<pY+5;j1++,j2++)
        {
            if (k->klocki[typ_klocka][rotacja_klocka][i2][j2] != 0)
                tablica[i1][j1]=k->klocki[typ_klocka][rotacja_klocka][i2][j2];
        }
    }
}
