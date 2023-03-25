#include<iostream>//动态规划模板
#include<math.h>
using namespace std;
int a[102];
int dp[102];
int n;
int sum=0;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&a[j]);
        }
        for(int j=i;j>=1;j--){
        dp[j]=max(dp[j]+a[j],dp[j-1]+a[j]);
            //cout<<dp[j]<<" ";
        }
        //cout<<endl;
    }
    for(int i=1;i<=n;i++){
        sum=max(sum,dp[i]);
    }
    cout<<sum;
}