#include<iostream>
using namespace std;

int main() {

    unsigned int n;
    cin >> n;

    while(n%10 == 0)
    {
        n /=10;
    }

    while(n!=0)
        {
            cout << n%10;
            n = (n-n%10)/10;
        }

  }

