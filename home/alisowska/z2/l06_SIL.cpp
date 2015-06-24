#include <iostream>
using namespace std;
int main(){
int n;
cin >> n;
int silnia = 1;
for (int i=0; i<=n; i++){
    if (i==0)
        silnia = 1;
    else
        silnia *= i;
}
cout <<silnia;
}
