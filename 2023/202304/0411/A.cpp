#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a, b;
        int ans=0;
        for (int i = 1;i<=n;i++){
            cin>>a>>b;
            ans += a * b;
        }
        cout<<ans<<endl;
    }
}