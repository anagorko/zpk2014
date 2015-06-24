#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n%10==0) //gdy n ma 0 na koncu!
        n=n/10;
    while (n!=0){
        cout << n%10;
        n=n/10;
    }
}
