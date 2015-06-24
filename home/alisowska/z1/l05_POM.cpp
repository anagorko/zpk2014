#include <iostream>
using namespace std;
int main (){
    int rozne = 0;
    int pomiar;
    int poziom = 0 ;
    cin >> pomiar;
    while (pomiar!=-1){
        cin >> pomiar;
        if (pomiar > poziom){
            poziom = pomiar;
            rozne++;}
    }
cout << rozne;
}
