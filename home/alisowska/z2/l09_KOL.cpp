#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
double r;
cin >> r;
double pole, obwod;
pole = M_PI * r *r;
obwod = 2 * M_PI * r;
cout << setprecision(3) <<fixed;
cout << pole << endl << obwod;
}
