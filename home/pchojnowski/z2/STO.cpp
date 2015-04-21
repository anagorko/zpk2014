#include <iostream>
using namespace std;

int main() {

int a,b,k;

cin>>a>>b>>k;

if(a>k && b>k){

if(a>=2*k && b>=2*k)
    cout<<2*(a/k) + 2*(b/k)-4;
    else if(a>=2*k && b<2*k)
        cout<< a/k;
    else cout<< b/k;

}
 if(a==k && b==k){
    if(a==0) cout<<'0';
      if(a>0) cout<<'1';

} else if(a>k && b<k){
     cout<<'0';

} else if(a<k && b<k){
     cout<<'0';

} else if(a==k && b>k){
     cout<<b/k;

} else if(a==k && b<k){
    cout<<'0';

} else if(a>k && b==k){
    cout<<a/k;

} else if(a<k && b==k){
      cout<<'0';

}
}
