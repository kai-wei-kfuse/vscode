#include<iostream>
using namespace std;
int dp[502][502][2];
int pp[502][502];
int main()
{
    int x,y,p,q;
    cin>>x>>y>>p>>q;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            scanf("%d",&pp[i][j]);
        }
    }
    for(int i=1;i<=x;i++){
        dp[i][1][0]=1;
        dp[i][1][1]=pp[i][1];
    }
    for(int i=1;i<=y;i++){
        dp[1][i][0]=1;
        dp[1][i][1]=pp[1][i];
    }
    for(int i=2;i<=x;i++){
        for(int j=2;j<=y;j++){
            dp[i][j][0]=dp[i-1][j][0]+dp[i][j-1][0];
            dp[i][j][1]+=pp[i-1][j]+pp[i][j-1]+pp[i][j];
        }
    }
    
}