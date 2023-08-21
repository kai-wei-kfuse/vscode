#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
     int t;
     cin>>t;
     while(t--){
        int n,k;
        cin>>n>>k;
        k--;
        vector<int >a(n+1),b(n+1),f(35,-1);
        //cout<<n<<endl;
        for(int i=1;i<n;i++){
            cin>>a[i];
            b[i]=b[i-1]^a[i];
            //cout<<b[i]<<" ";
        }
        //cout<<endl;
        int flag=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0)continue;
            int tmp=29;
            while((a[i]&(1<<tmp))==0)tmp--;
            int o=(b[i-1]>>tmp)&1;
            //cout<<b[i]<<"?";
            //cout<<o<<' '<<tmp<<endl;
            if(f[tmp]==-1)
                f[tmp]=o;
            else if(f[tmp]!=o){
                flag=1;
                break;
            }
        }
        if(flag){
            cout<<-1<<endl;
            continue;
        }
        int cnt=0;
        for(int i=0;i<30;i++){
            if(f[i]==-1){
                f[i]=(k>>cnt)&1;
                cnt++;
            }
        }
        if(k>>cnt){
            cout<<-1<<endl;
            continue;
        }
        vector<int >ans(n+1);
        for(int i=0;i<30;i++){
            ans[1]+=f[i]*(1<<i);
        }
        if(ans[1]>(1<<30)){
            cout<<-1<<endl;
            continue;
        }
        for(int i=2;i<=n;i++){
            ans[i]=ans[1]^b[i-1];
            if(ans[i]>(1<<30)){
                flag=1;
                break;
            }
        }
        if(flag){
            cout<<-1<<endl;
            continue;
        }else{
            for(int i=1;i<=n;i++){
                cout<<ans[i]<<' ';
            }
            cout<<endl;
        }
     }
}