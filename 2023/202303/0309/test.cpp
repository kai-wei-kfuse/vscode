#include<bits/stdc++.h>
using namespace std;
#define int long long

int lcm(int a,int b){
    return a * b / __gcd(a, b);
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n, a, d;
        cin >> n >> a >> d;
        cout << lcm(n, d) / d << endl;
    }
}