#include <iostream>
#include <string>

using namespace std;

int main() {
    string nazwa;
    cin >> nazwa;
    for ( int i = 0; i < nazwa.length(); i++){
        if (nazwa[i] != nazwa[nazwa.length()-i-1]){
            cout << "NIE";
        return 0;
    }}
    cout << "TAK" << endl;
}

