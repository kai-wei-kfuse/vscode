#include<iostream>
using namespace std;
int n,m,eat[5005],ate[5005],mp[5005][5005],mod=80112002,ans=0,rem[5005];
int dfs(int x){
    if(!eat[x])return 1;
    if(rem[x])return rem[x];
    int sum=0;
    for(int i=1;i<=n;i++){//枚举所有x吃的生物
        if(mp[i][x]){
            sum=(sum+dfs(i))%mod;//食物链数等于x吃的 所有动物 构成的食物链数加起来
        }
    }
    return rem[x]=sum;
}
int main()
{
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=m;i++){
        cin>>x>>y;//x是被吃，y是吃
        mp[x][y]=1;
        eat[y]++;
        ate[x]++;//eat指他吃几种动物，ate指他被几种动物吃
    }
    for(int i=1;i<=n;i++){
        if(!ate[i]){//如果是食物链顶端，那么为0
            ans=(ans+dfs(i))%mod;
        }
    }
    cout<<ans;
}