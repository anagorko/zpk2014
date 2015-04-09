#include <iostream>
using namespace std;

int main()
    {
    int n;
    cin >> n;

    int a;
   int t[n];

    for (int i = 0; i <= n - 1; i++)
        cin >> t[i];

    for (int i = 0; i <= n - 2; i++)
    {
        a = t[i + 1];
        while (a != 0)
        {
            t[i + 1] = a;
            a = max(t[i], t[i + 1]) % min(t[i], t[i + 1]);
        }
        t[i + 1] = min(t[i], t[i + 1]);
    }

    cout << t[n - 1] << endl;
}
