#include <iostream>
#include<string>

using namespace std;
int main(){
    string a, b, znak;
    bool wynik = true;
    cin >> a >> znak >> b;
    if (a.size() > b.size() && (znak == "==" || znak == "<" || znak == "<="))
        wynik = false;
    if (a.size() > b.size() && (znak == "!=" || znak == ">" ||  znak == ">="))
        wynik = true;
    if (a.size() < b.size() && (znak == "==" || znak == ">" || znak == ">="))
        wynik = false;
    if (a.size() < b.size() && (znak == "!=" || znak == "<" ||  znak == "<="))
        wynik = true;
    if (a.size() == b.size())
        for (int i=0; ; i++){
            if (a[i]>b[i] && (znak == "==" || znak == "<" || znak == "<="))
                wynik = false;
                break;
           if(a[i] < b[i] && (znak == "==" || znak == ">" || znak == ">="))
                wynik = false;
                break;}
    if (wynik == true)
        cout << "TAK";
    else
        cout << "NIE";


}
