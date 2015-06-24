#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    int g, m, s;
    s = t % 60; //sekundy
    g = t / 3600; //godziny
    m = (t - s - 3600 * g )/60; // minuty
    cout << g <<"g"<< m << "m" <<s << "s";
}
