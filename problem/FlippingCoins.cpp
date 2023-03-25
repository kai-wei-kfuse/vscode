#include<iostream>//概率dp
#include<cstdio>
using namespace std;
double dp[402][402];
int main()
{
    int n,k;
    double ans=0;
    cin>>n>>k;
    dp[0][0]=1;
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            dp[i+1][j]+=dp[i][j]*0.5;
            dp[i+1][j+1]+=dp[i][j]*0.5;
        }
        dp[i+1][n]+=dp[i][n]*0.5;
        dp[i+1][n-1]+=dp[i][n]*0.5;
    }
    for(int i=1;i<=n;i++){
        ans+=dp[k][i]*i;
    }
    printf("%.6f\n", ans);
}