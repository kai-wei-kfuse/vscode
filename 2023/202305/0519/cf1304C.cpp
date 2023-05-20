#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,s;
        cin>>n>>s;
        int x=0;
        int maxn=s,minn=s;
        int flag=0;
        for(int i=1;i<=n;i++){
            int tt,mx,mi;
            cin>>tt>>mi>>mx;
            int min_=minn-(tt-x);
            int max_=maxn+tt-x;
            if(mx>=min_&&mi<=max_){
                maxn=min(max_,mx);
                minn=max(min_,mi);
                //cout<<maxn<<' '<<minn<<endl;
            }else{
                flag=1;
            }
            x=tt;
        }
        if(flag){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
    }
}