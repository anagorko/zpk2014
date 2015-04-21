#include <iostream>
using namespace std;

int main(){
int rok, a, b, c, d, e, A, B;
cin>>rok;

a=rok%19;
b=rok%4;
c=rok%7;

if(rok>=1800 && rok<=1899) {A=23; B=4;}

if(rok>=1900 && rok<=2099) {A=24; B=5;}

//    if(rok==1981 || rok==2076 || rok==1954 || rok==2049)

if(rok>=2100 && rok<=2199){A=24; B=6;}
   // if(rok==2201 || rok==2296)



d=(a*19+A)%30;
e=(2*b+4*c+6*d+B)%7;
if(d==29 && e==6) cout<<19<<" "<<4;
else if(d==28 && e==6 && a>10) cout<<18<<" "<<4;
else if(d+e<10) cout<<d+e+22<<" "<<3;
else cout<<d+e-9<<" "<<4;


}
