#include <iostream>
#include <string>
using namespace std;
int main(){
    string slowo;
    cin >> slowo;
    int r = slowo.size();
    bool palindrom = true;
    for (int i = 0; i<=r ; i++, r--)
            if ( slowo[i] != slowo[r-1]){
                palindrom = false;
                break;
            }
    if (palindrom)
        cout << "TAK";
    else
        cout << "NIE";
}
