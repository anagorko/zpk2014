#include "clsLudzik.h"
#include "clsSkrzynka.h"

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

/*
bool clsLudzik::MozliwyRuch(clsPlansza p, char pchrKierunek)
{
    switch(pchrKierunek)
            {   case 'D':
                    if ( intPozycjaWiersz + 1 == (0 || 6)) // podloga albo cel
                    { return 1; }

                    else if (intPozycjaWiersz + 1 == (4 || 5)) //skrzynka albo skrzynka na celu
                    {return 0; }
                    //{ return (clsSkrzynka().MozliwyRuch(pchrKierunek)); }
                    break;

                case 'G':
                    if ( intPozycjaWiersz - 1 == (0 || 6)) // podloga albo cel
                    { return 1; }

                    else if (intPozycjaWiersz - 1 == (4 || 5)) //skrzynka albo skrzynka na celu
                    {return 0; }
                    //{ return (clsSkrzynka().MozliwyRuch(pchrKierunek)); }
                    break;

                  case 'P':
                    if ( intPozycjaKolumna + 1 == (0 || 6)) // podloga albo cel
                    { return 1; }

                    else if (intPozycjaKolumna + 1 == (4 || 5)) //skrzynka albo skrzynka na celu
                    {return 0; }
                    //{ return (clsSkrzynka().MozliwyRuch(pchrKierunek)); }
                    break;

                case 'L':
                    if ( intPozycjaKolumna - 1 == (0 || 6)) // podloga albo cel
                    { return 1; }

                    else if (intPozycjaKolumna - 1 == (4 || 5)) //skrzynka albo skrzynka na celu
                    {return 0; }
                    //{ return (clsSkrzynka().MozliwyRuch(pchrKierunek)); }
                    break;
            }
    return 0 ;
}
*/
