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

    bool clsSkrzynka::CzyUkonczono(clsPlansza p)
    {   bool ukonczono = 1;

        for(int i = 0; i < intWiersze; i++)
        {   for(int j = 0; j < intKolumny; j++)
            {   if(tblSkrzynkiS[i][j] && p.get_tblPodloga(i, j) != 6)
                {   ukonczono = 0;
                }
            }
        }
        return ukonczono;
    }
