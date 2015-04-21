#include <iostream>
using namespace std;

int main(){

int a,b,k;
cin>>a>>b>>k;

int pierwsza=0;
int druga=0;
int n=0;

if(b>a){
    if(a%k==0) pierwsza=a/k;
    else pierwsza=(a/k+1);
    druga=b/k;
    n=druga-pierwsza+1;

}

if(b==a && b%k==0) n=1;

cout<<n;

}
