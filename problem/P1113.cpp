#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector< int >edge[100005];
int dp[100005],t[100005];
int ans=0;
int dfs(int x)
{
    if(dp[x])return dp[x];
    for(int i=0;i<edge[x].size();i++){
        dp[x]=max(dp[x],dfs(edge[x][i]));
    }
    dp[x]+=t[x];
    return dp[x];
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>t[i];
        cin>>y;
        while(y){
            edge[y].push_back(x);
            cin>>y;
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,dfs(i));
        }
    cout<<ans;
}