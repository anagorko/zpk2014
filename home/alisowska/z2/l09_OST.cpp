#include <iostream>
using namespace std;
int main(){
    int n, w;
    cin >> n;

    if(n == 0)
        w = 1;
    else if(n%4 == 0)
        w = 6;
    else if(n%4 == 1)
        w = 2;
    else if(n%4 == 2)
        w = 4;
    else if(n%4 == 3)
        w = 8;

    cout << w;
    }
