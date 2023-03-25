#include<iostream>
#include<vector>
using namespace std;
#define mod 998244353
int dp[500005];
int main()
{
    int n;
    cin>>n;
    n/=2;
    n++;
    dp[1]=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            dp[j]=dp[j-1]%mod+dp[j]%mod;
            //cout<<dp[j]<<' ';
        }
        //cout<<endl;
    }
    cout<<dp[n];
}