#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    double promien;
    cin >> promien;

    cout << setprecision(3) << fixed;

    cout << pow( promien, 2) * M_PI << endl;


}
