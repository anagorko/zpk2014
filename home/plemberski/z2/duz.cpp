#include <iostream>
#include <cstring>
using namespace std;

//dwie funkcje

bool czy_x_wieksza(string x, string y){
      int m = 0;
if (x.size() > y.size()) return true;
else{
if (x.size() < y.size()) return false;
else{
    for(int i = 0; i < x.size(); ++i){
        if (x[i] > y[i]) return true;
        else if (x[i] < y[i]) return false;
        else if (x[i] == y[i]) ++m;
    }
 }
if (m == x.size()) return false;
}
}

bool czy_y_wieksza(string x, string y){
     int m = 0;
if (x.size() < y.size()) return true;
else{
if (x.size() > y.size()) return false;
else{
    for(int i = 0; i < x.size(); ++i){
        if (x[i] < y[i]) return true;
        else if (x[i] > y[i]) return false;
        else if (x[i] == y[i]) ++m;
    }
 }
if (m == x.size()) return false;
}
}

int main() {

string x, y, znak;
cin>> x >> znak >> y;

if (znak == "<"){
 if (czy_y_wieksza(x,y)==true) cout<< "TAK" <<endl;
                              else  cout<< "NIE" <<endl;
}
else if (znak == ">"){
 if (czy_x_wieksza(x,y)==true) cout<< "TAK" <<endl;
                               else cout<< "NIE" <<endl;
}
else if (znak == "<="){
 if (czy_y_wieksza(x,y)==true || (czy_x_wieksza(x,y)==false && czy_y_wieksza(x,y)==false)) cout<<"TAK" << endl;
                                                                                      else  cout<<"NIE" << endl;
}
else if (znak == ">="){
 if (czy_x_wieksza(x,y)==true || (czy_x_wieksza(x,y)==false && czy_y_wieksza(x,y)==false)) cout<<"TAK" << endl;
                                                                                       else cout<<"NIE" << endl;
}
else if (znak == "=="){
 if (czy_x_wieksza(x,y)==false && czy_y_wieksza(x,y)==false) cout<<"TAK" << endl;
                                                          else  cout<<"NIE" << endl;
}
else if (znak == "!="){
 if (czy_x_wieksza(x,y)==true || czy_y_wieksza(x,y)==true) cout<<"TAK" << endl;
                                                           else cout<<"NIE" << endl;
}
}

