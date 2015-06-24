#include "clsSkrzynka.h"

//konstruktor
    clsSkrzynka::clsSkrzynka(clsPlansza p)
    {   for(int i = 0; i < intWiersze; i++)
        {   for(int j = 0; j < intKolumny; j++)
            {   tblSkrzynkiS[i][j] = p.get_tblSkrzynkiP(i, j);
            }
        }
    }

//destruktor
    clsSkrzynka:: ~clsSkrzynka()
    {
        delete []tblSkrzynkiS;
    }

//funkcja
    bool clsSkrzynka::CzyUkonczono(clsPlansza& p)
    {   bool ukonczono = 1;

        for(int i = 0; i < intWiersze; i++)
        {   for(int j = 0; j < intKolumny; j++)
            {   if(tblSkrzynkiS[i][j] == 1 && p.get_tblPodloga(i, j) != 6)
                {   ukonczono = 0;
                }
            }
        }

        if (ukonczono)
        {   p.set_tblUkonczone(ukonczono);

            int a = p.get_level() + 1;
            p.set_level(a);
       }

       if(p.get_level() > p.get_LiczbaPlansz()) // jesli to ostania plansza
       {
           cout << "To jest juz koniec!";
       }
        return ukonczono;
    }
