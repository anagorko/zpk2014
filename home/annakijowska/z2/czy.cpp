#include <iostream>
using namespace std;

int main() {
    long long i;
    cin >> i;
    bool niezapetli=true;
    while (niezapetli && i>1){
        if (i%2==0)
            i=i/2;

        else
            niezapetli=false;
    }
    if (niezapetli==false)
        cout << "NIE" << endl;
    else
        cout << "TAK" << endl;

}
