#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
     int t;
     cin>>t;
     while(t--){
        int n;
        cin>>n;
        vector<int >ve(n+1);
        for(int i=1;i<=n;i++){
            cin>>ve[i];
        }
        int ans=0;
        int flag=0;
        int maxn=0;
        for(int i=n-1;i>=1;i--){
            if(ve[i]>ve[i+1]){
                flag=1;
            }
            if(flag){
                maxn=max(maxn,ve[i]);
            }
        }
        cout<<maxn<<endl;
     }
}