#include<iostream>
using namespace std;
struct xx{
    int x,y;
    int val;
}a[1005];
long long dp[1005];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].val;
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            if(j>=a[i].val)
            dp[j]=max(dp[j]+a[i].x,dp[j-a[i].val]+a[i].y);
            else {
                dp[j]=dp[j]+a[i].x;
            }
        }
    }
    cout<<dp[m]*5;
}