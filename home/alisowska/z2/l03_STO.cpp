#include <iostream>
using namespace std;
int main (){
    int a, b, k;
    cin >> a >> b >> k;
    if (a <= 0 || b <= 0 || k <= 0 || a < k || b < k )
        cout << 0;
    else if (a < 2* k && b < 2 * k)
        cout << 1;
    else if (a < 2 * k)
        cout << b/k;
    else if ( b < 2 * k)
        cout << a/k;
    else
        cout << (a - k )/ k * 2 + (b - k) / k * 2 ;
}
