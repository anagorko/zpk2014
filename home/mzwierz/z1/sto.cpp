#include <iostream>
using namespace std;

int main(){

int A, B, K;
cin>>A>>B>>K;
int liczba =0;

int bok_1=A/K;
int bok_2=B/K;

if(bok_1<1 && bok_2<1){
    liczba=0;
}


if(bok_1>2 && bok_2>2){

    liczba = bok_1*bok_2;
    liczba = liczba - (bok_1-2)*(bok_2-2);
}

else{
    liczba = bok_1*bok_2;
}

cout<<liczba;


}
