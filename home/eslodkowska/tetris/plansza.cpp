#include plansza.h

void Plansza::pusta_plansza()
{
     for (int i=0;i<wysokosc;i++)
        for (int j=0;j<szerokosc;j++)
        tablica [i][j]=0;
}

void Plansza::zapelnij_plansze()
{
    ...
}

    bool Plansza::czy_kolizja(int X, int Y, int typ_klocka, int rotacja_klocka)


{
    for (int i1 = pX, i2 = 0; i1 < X + 5; i1++, i2++)
    {
        for (int j1 = pY, j2 = 0; j1 < Y + 5; j1++, j2++)
        {
            // czy klocek wychodzi poza plansze
            if (    i1 < 0           ||
                i1 > szerokosc  - 1    ||
                j1 > wysokosc - 1)
            {
                    if (klocki[typ_klocka][rotacja_klocka][j2][i2] != 0)
                    return 1;
            }

            // czy klocek nachodzi na inny juz na planszy
            if (j1 >= 0)
            {
                if (klocki[typ_klocka][rotacja_klocka][j2][i2] != 0 &&
                    tablica[i1][j1]!=0 )
                    return 1;
            }
        }
    }

    // brak kolizji
    return 0;
}



    void Plansza::usun_linie(wiersz)
    {
        for (int i=0;i<szerokosc;i++)
            tablica[wiersz][i]=0;
        punkty++;

        for (int j=0;j<szerokosc;j++)
            for (int k=wiersz-1;k>=0;k--)
                tablica[k+1][j]=tablica[k][j];


    }
    bool Plansza::czy_cala_linia(wiersz)
    {
        for (int i=0;i<szerokosc;i++)
           if (tablica[wiersz][i]=0) { return 0;}
        return 1;

    }

    bool Plansza::czy_koniec_poziomu(poziom)
    {
        if (poziom=1 and punkty>1000) then return true;
            else if (poziom=2 and punkty>2000) then return true;
            else if (poziom=3 and punkty>3000) then return true;
            else return false;
    }

bool Plansza::czy_przegrana()
{

    for (int i = 0; i < szerokosc; i++)
    {
        if (tablica[i][0] == 1) return true;
    }

    return false;
}




