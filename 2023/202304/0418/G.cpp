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
    //now=a[1].first;
    for(int i=1;i<=m;i++){
        x+=a[i].second;
        //cout<<x<<endl;
        if(i>1)
            x=max(0LL,x-(a[i].first-now-1)*k);
        if(a[i].first>=t&&flag==0){
            int tmp;
            if(a[i].first==t)
                tmp=x;  
            else
                tmp=max(0LL,x-a[i].second);
            //cout<<tmp<<" "<<x<<endl;
            if(tmp!=n){
                cout<<"Wrong Record"<<endl;
                return 0;
            }
            flag=1;
        }
        if(flag){
            if(minn>=(x+k)/k){
                minn=(x+k)/k;
                ans=a[i].first;
            }
        }
        x=max(0LL,x-k);
        cout<<x<<endl;
        now=a[i].first;
    }
    cout<<ans<<' '<<minn<<endl;
}