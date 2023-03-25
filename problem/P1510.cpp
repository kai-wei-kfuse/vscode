#include<iostream>
#include<algorithm>
int V,n,m,v[10002],p[10002],dp[10002];
using namespace std;
int main()
{
    cin>>V>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d %d",&v[i],&p[i]);
    }
    for(int j=1;j<=n;j++){
        for(int k=m;k>=p[j];k--){
            dp[k]=max(dp[k],dp[k-p[j]]+v[j]);
        }//每种体力所取石头的最大体积
    }
    for(int i=1;i<=m;i++){
        if(dp[i]>=V){
            cout<<m-i;
            return 0;
        }
    }
    cout<<"Impossible";
    return 0;
}