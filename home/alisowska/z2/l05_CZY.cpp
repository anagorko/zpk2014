#include <iostream>
using namespace std;
int main(){
long long i;
cin >> i;
while(i%2==0)
    i/=2;
if (i!=1)
    cout <<"NIE";
else
    cout <<"TAK";
}
