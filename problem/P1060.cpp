#include<iostream>
using namespace std;
int c[26],v[10002],dp[30002];
;int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        scanf("%d %d",&c[i],&v[i]);
    }
    for(int i=1;i<=m;i++){
        for(int j=n;j>=c[i];j--){
            dp[j]=max(dp[j],dp[j-c[i]]+c[i]*v[i]);
        }
    }
    cout<<dp[n];
}