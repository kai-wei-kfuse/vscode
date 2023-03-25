#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a=0, b=0;
        for (int i = 1; i <= n;i++){
            int tmp;
            cin >> tmp;
            a += tmp;
            b ^= tmp;
        }
        cout << "2" << endl;
        cout << a + b << ' ' << b << endl;
    }
}