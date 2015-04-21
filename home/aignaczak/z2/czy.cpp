#include <iostream>
using namespace std;

int main(){
    unsigned long long i;
    int k;
    cin >> i;

    while (i != 1){
        if (i % 2 == 0){
            if (i == 2){
                k = 1;
                break;
            }
            i = i / 2;
        }
        else{
            k = 2;
            break;
        }
    }

    if (k == 1)
        cout << "TAK" << endl;
    else
        cout << "NIE" << endl;
}
