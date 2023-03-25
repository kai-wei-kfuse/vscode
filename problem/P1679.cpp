#include<iostream>
#include<cstring>
using namespace std;
long long dp[100010];
long long a[100];
int main()
{
    memset(dp,127,sizeof(dp));
    dp[0]=0;
    int m,n;
    cin>>m;
    for(int i=1;i*i*i*i<=m;i++){
        a[i]=i*i*i*i;
        n=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=a[i];j<=m;j++){
            dp[j]=min(dp[j],dp[j-a[i]]+1);
        }
    }
    cout<<dp[m];
}