#include <iostream>
using namespace std;

int main(){

int s;
cin>>s;

int m=s/60;
int g=m/60;
s=s-60*m;
m=m-60*g;

cout<<g<<"g"<<m<<"m"<<s<<"s";

}
