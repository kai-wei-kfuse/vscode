#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>ve(n+1);
        for(int i=1;i<=n;i++){
            cin>>ve[i];
        }
        sort(ve.begin()+1,ve.end());
        int maxn=-1e18;
        for(int i=2;i<=n;i++){
            maxn=max(maxn,ve[i]*ve[i-1]);
        }
        cout<<maxn<<endl;
    }
}