#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    int r,b;
    for(int i=1;i<=t;i++){
        cin >> r>>b;
        cout << "Case #" << i << ": ";
        int d = (r + b)*(r+b-1);
        int s = r*(r-1);
        if(__gcd(d,s)!=1){
            cout << s / __gcd(d, s) << '/' << d / __gcd(d, s) << '\n';
        }
        else{
            cout << s << '/' << d << '\n';
        }
    }
}