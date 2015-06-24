#include <iostream>
using namespace std;
int main(){
char a;
char b;
cin >> a >> b;
int x; //pomocnicza zmienna do b
if ((int)b > 47 && (int)b < 58)
    x = (int)b - 48;
else if ((int)b > 64 && (int)b <71)
    x = (int)b - 55;
int kod;
int y; //pomocnicza zmienna do a
y = (int)a - 48;
kod = y * 16 + x;
cout << kod << endl << char(kod) ;
}
