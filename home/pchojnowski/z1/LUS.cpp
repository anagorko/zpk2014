#include <iostream>
using namespace std;

int main(){

long long n, b=0, bufor=0, e=1;
cin>>n;
b=n;
if(n%10!=0);
else
while(b%10==0){
    b=b/10;
    e=e*10;
}
n=n/e;
while(n>=1){

    bufor=n%10;
    n=n/10;

cout<<bufor;
}


}
