#include<iostream>
using namespace std;
int a[22];
int vis[22];
int vis2[22];
int n,k,sum=0,ans;
void dfs(int x,int now,int sum){
    if(x>k){
        for(int i=2;i<=sum/i;i++){
            if(sum%i==0)return;
        }
        //for(int i=1;i<=n;i++)cout<<vis2[i]<<' ';
        //cout<<sum<<endl;
        ans++;
        return;
    }
    for(int i=now;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(x+1,i,sum+a[i]);
            vis[i]=0;
        }
    }
    return;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,1,sum);
    cout<<ans;
}