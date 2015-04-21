#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

int main(){
string s,znak,s2;
long long ds, dznak, ds2;
int i=0;
bool bufor=0, bufor2=0;

cin>>s>>znak>>s2;

ds=s.length();
dznak=znak.length();
ds2=s2.length();


if(znak[0]=='<' && znak[1]=='\0')
    {
     if(ds>ds2) cout << "NIE";
else if(ds<ds2) cout << "TAK";
else{


        do{
                if(s[i]>s2[i]) bufor=1;

                if(s[i]<s2[i]) bufor2=1;

            i++;

     }while(i<ds  && bufor2==0 && bufor==0);


    if(bufor2) cout<< "TAK";
    else cout << "NIE";
}
}
else








     if(znak[0]=='>' && znak[1]=='\0') {
     if(ds<ds2) cout << "NIE";
else if(ds>ds2) cout << "TAK";
else{


        do{
                if(s[i]<s2[i]) bufor=1;

                if(s[i]>s2[i]) bufor2=1;

            i++;

     }while(i<ds  && bufor2==0 && bufor==0);


    if(bufor2) cout<< "TAK";
    else cout << "NIE";

    }
    }else










    if(znak[0]=='!' && znak[1]=='=') {
        if(ds!=ds2) cout << "TAK";
else{
    for(int i=0; i<ds; i++)
    if(s[i]!=s2[i]) bufor=1;
        if(bufor) cout<< "TAK";
    else cout << "NIE";
    }
    }else









    if(znak[0]=='=' && znak[1]=='=') {
    if(ds!=ds2) cout << "NIE";
else{
    for(int i=0; i<ds; i++)
    if(s[i]!=s2[i]) bufor=1;
        if(bufor) cout<< "NIE";
    else cout << "TAK";
    }
    }else












    if(znak[0]=='<' && znak[1]=='=') {
    if(ds>ds2) cout << "NIE";
else if(ds<ds2) cout << "TAK";
else{

    do{
        if(s[i]>s2[i]) bufor=1;
        if(s[i]<s2[i]) bufor2=1;
        i++;
    }while(i<ds && bufor==0 && bufor2==0 );

    if(bufor) cout<< "NIE";
    else cout << "TAK";
    }
    }else


     if(znak[0]=='>' && znak[1]=='=') {
     if(ds<ds2) cout << "NIE";
else if(ds>ds2) cout << "TAK";
else{
    do{
        if(s[i]<s2[i]) bufor=1;
        if(s[i]>s2[i]) bufor2=1;
        i++;
    }while(i<ds && bufor==0 && bufor2==0);
    if(bufor) cout<< "NIE";
    else cout << "TAK";
    }

     }



}

