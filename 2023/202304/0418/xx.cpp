#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t,n;
    cin>>t>>n;
    int m,k;
    cin>>m>>k;
    int now=0,x=0,flag=0,minn=0x3f3f3f3f3f3f,ans;
    vector<pair<int,int>>a(m+1);

    for(int i=1;i<=m;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin()+1,a.end());

    for(int i=1;i<=m;i++){
        //cout<<x<<endl;
        if(a[i].first>=t&&flag==0){
            int tmp;
            if(a[i].first==t)
                tmp=x+a[i].second;  
            else
                tmp=max(0LL,x-(t-now-1)*k);
            //cout<<tmp<<" "<<x<<endl;
            if(tmp!=n){
                cout<<"Wrong Record"<<endl;
                return 0;
            }
            flag=1;
        }
        x+=a[i].second;
        if(flag){
            if(minn>=(x+k)/k){
                minn=(x+k)/k;
                ans=a[i].first;
            }
        }
        x=max(0LL,x-(a[i].first-now)*k);
        //cout<<x<<endl;
        now=a[i].first;
    }
    cout<<ans<<' '<<minn<<endl;
}