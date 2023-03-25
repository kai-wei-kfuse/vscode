#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
double dp[1002];
int main()
{
    int t;
    cin>>t;
    int n;
    int a=0;
    while(t--){
        cin>>n;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            cin>>dp[i];
        for(int i=n-1;i>=1;i--){
            for(int j=1;j<=6;j++){
            dp[i]+=dp[i+j]/(1.0*min(6,n-i));
            }
        }
        printf("Case %d: %lf\n",++a,dp[1]);
    }
}