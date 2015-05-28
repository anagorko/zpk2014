#include <iostream>
using namespace std;

int main() {

int c;
char a, b, d;

cin >> a >> b;
if((int)b>64){
    c = ((int)a - 48) * 16 + (int)b-55;
    d=(char)c;
}
else {
    c = ((int)a - 48) * 16 + (int)b-48;
    d=(char)c;
}

cout << c << endl;
cout << d << endl;

}
