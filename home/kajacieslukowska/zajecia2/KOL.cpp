#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){

    double r;
    cin >> r;

    cout << fixed << setprecision(3) << M_PI*r*r << endl;
    cout << fixed << setprecision(3) << 2*M_PI*r << endl;

}
