#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int w = 1;
    for( int i = 1; i < n + 1; i++ ){
        w *= i;
    }
    cout << w << endl;
}

