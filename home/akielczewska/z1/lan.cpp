#include <iostream>
using namespace std;

main() {
   char szest1, szest2;
   cin >> szest1 >>  szest2;
   int ascii;
   ascii = int(szest1) * 16 + int(szest2);
   cout << ascii;
}
