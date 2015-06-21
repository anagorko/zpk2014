#include <iostream>
using namespace std;

int main() {
    int A, B, a, b, c, d, e, r;
    cin >> r;

    if(r>=1800&&r<1900){
        A=23; B=4;
    }
    else if (r>=1900&&r<2100) {
        A=24; B=5;
    }
     else  {
        A=24; B=6;
    }

    a=r%19;
    b=r%4;
    c=r%7;
    d=(a*19+A)%30;
    e=(2*b+4*c+6*d+B)%7;

    if (r==1981||r==2076||r==2133)
    {
        cout<<19<<" "<<4;
    }
     else if(r==1954||r==2049||r==2106){
        cout << 18<<" "<<4;
     }

    else if(d+e<10){
        cout<< d+e+22 << " "<< 3;
    }
    else
        cout << d+e-9 << " " << 4;
}
