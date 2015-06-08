#include <iostream>
#include <string>

using namespace std;

int NWD(int a, int b){
    int r = a%b;
        while (r != 0){
            a = b, b = r, r = a%b;
        }
        return b;
}

int main(){
int a, b;
cin >> a >> b;
cout << NWD(a, b) << endl;

}
