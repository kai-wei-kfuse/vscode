#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,d;
        cin>>n>>m>>d;
        vector<int > ve;
        ve.push_back(1);
        for(int i=1;i<=m;i++){
            int tmp;
            cin>>tmp;
            ve.push_back(tmp);
        }
        int ans=0;
        // if(ve[m]!=n)
        // if(ve[m]==n){
        //     ans++;
        // }
        ve.push_back(n+1);
        
        
        int len=ve.size();
        int fl=0;
        int cnt=0;
        // cout<<d<<":";
        // for(auto it : ve){
        //     cout<<it<<' ';
        // }
        // cout<<endl;
        // if(ve[1]==1){
        //     ans--;
        // }
        for(int i=1;i<len-1;i++){
            ans+=(ve[i]-ve[i-1]+d-1)/d;
                //cout<<"h"<<endl;
                //cout<<(ve[i]-ve[i-2]+d-1)/d<<' '<<(ve[i]-ve[i-1]+d-1)/d+(ve[i-1]-ve[i-2]+d-1)/d<<endl;
                if((ve[i+1]-ve[i-1]+d-1)/d<(ve[i]-ve[i-1]+d-1)/d+(ve[i+1]-ve[i]+d-1)/d){
                    //cout<<"?"<<endl;
                    //ans--;
                    fl=1;
                    cnt++;
                
            }
        }
        ans+=(ve[len-1]-ve[len-2]+d-1)/d;
        //cout<<"x"<<endl;
        if(fl==0){
           //cout<<"x"<<" ";
            cout<<ans<<' '<<m<<endl;
        }else{
            cout<<ans-1<<' '<<cnt<<endl;
        }
    }
}