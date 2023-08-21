#include<bits/stdc++.h>
using namespace std;

#define int long long 

struct xx{
    int x,id;
};

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<xx >ve(n+1);
        map<int ,int >mp;
        for(int i=1;i<=n;i++){
            cin>>ve[i].x;
            ve[i].id=i;
            mp[ve[i].x]++;
        }
        sort(ve.begin()+1,ve.end(),[](xx a,xx b){
            return a.x<b.x;
        });
        vector<int >ans(n+1,0);
        int cnt=0;
        for(int i=2;i<=n;i++){
            if(ve[i].x==ve[i-1].x){
                continue;
            }
            cnt+=(ve[i].x-ve[1].x+1);
        }
        //cout<<cnt<<endl;
        cnt+=mp[ve[1].x];
        int num=0;
        for(int i=1;i<=n;i++){
            if(i>1&&ve[i].x!=ve[i-1].x){
                int dis=ve[i].x-ve[i-1].x+1;
                //cout<<dis<<" ";
                cnt+=(dis-1)*(i-1);
                cnt-=(dis-1)*(n-i+1);
                //cout<<cnt<<endl;
            }
            ans[ve[i].id]=cnt;
        }
        //cout<<endl;
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}