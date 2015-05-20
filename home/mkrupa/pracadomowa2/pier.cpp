#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, i;
    cin >> a;
    int c = 0;
        for ( int i = 2; i <= sqrt(a); i++ ){
        b = a%i;
        if (b == 0){
        cout << "zlozona";
        return 0;
        }

}
cout << "pierwsza" << endl;
}
