#include <iostream>
using namespace std;

int main()
{
    unsigned int n, i = 2;
    cin >> n;
    string wynik = "pierwsza";
    while (i * i <= n && wynik == "pierwsza")
    {
        if (n % i == 0)
            wynik = "zlozona";
        i++;
    }
    cout << wynik << endl;
}
