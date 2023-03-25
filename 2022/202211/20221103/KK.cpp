#include<bits/stdc++.h>
using namespace std;
int main(){
    double pi = acos(-1);
    double a, x;
    cin >> a >> x;
   // cout << 1.0 / sqrt(3) << endl;
   // cout << tan(a / 180.0 * pi) << endl;
    // cout << x / 2.0 << endl;
    // cout << acos(-1) << endl;
    cout <<fixed<<setprecision(8)<< 2.0 * pi * (x *cos(a/180.0*pi))*tan(a/180.0/2*pi) ;

}