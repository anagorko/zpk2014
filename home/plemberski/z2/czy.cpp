/* jedyna mozliwoscia zatrzymania petli jest niespelnienie warunku (i !=1), czyli dojscie do komentu kiedy i=1.

Wynik taki mo�emy uzyska� jedynie wtedy kiedy i jest wielokrotno�ci� cyfry 2 (2^k dla dowolnich k naturalnych).
Wtedy p�tla korzysta jedynie z instrukcji przypisanej na warunku if = true. Co w konsekwencji w ostatnim obrocie petli (i = i/2 => 1=2/2) spowoduje zatrzymanie petli

"Wpadniecie" cho� raz w instrukcje else dla warunku if r�wnego false spowoduje i� nie bedzie mo�liwe wyjscie z pentli.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
long long i;
cin >> i;

    while (i != 1)
    {
        if (i%2 == 0)
        {
            if (i == 2)
                cout <<"TAK"<< endl;
            i = i / 2;
        }
        else
        {
            cout <<"NIE"<< endl;
            i = 1;
        }
    }
}
