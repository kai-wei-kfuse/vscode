#include<iostream>//动态规划模板
#include<algorithm>
using namespace std;
int t,num,c[102],v[102],dp[1002]={0};
int main()
{
    cin>>t>>num;
    for(int i=1;i<=num;i++){
        scanf("%d %d",&c[i],&v[i]);
    }
    for(int i=1;i<=num;i++){
        //cout<<i<<'|';
        for(int j=t;j>=c[i];j--){
            dp[j]=max(dp[j],dp[j-c[i]]+v[i]);
            //cout<<dp[j]<<' ';
        }
        for(int j=1;j<=t;j++){
            //cout<<dp[j]<<' ';
        }
        //cout<<endl;
    }
    cout<<dp[t];
}