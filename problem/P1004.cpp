#include<iostream>
using namespace std;
int x,y,m;
int dp[12][12][12][12],a[12][12];
int main()
{
    int n;
    cin>>n;
    cin>>x>>y>>m;
    while(x!=0 || y!=0 || m!=0){
        a[x][y]=m;
        cin>>x>>y>>m;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                for(int l=1;l<=n;l++){
                    dp[i][j][k][l]=max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]))+a[i][j]+a[k][l];
                    if(i==k && j==l)dp[i][j][k][l]-=a[i][j];
                }
            }
        }
    }
    cout<<dp[n][n][n][n];
}