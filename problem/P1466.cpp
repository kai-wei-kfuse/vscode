#include<iostream>
using namespace std;
long long dp[800];
int main()
{
    int n;
    cin>>n;
    int sum=(1+n)*n/2;
    dp[0]=1;
    if(sum%2!=0)cout<<'0';
    else{
    for(int i=1;i<=n;i++){
        for(int j=sum/2;j>=i;j--){
            dp[j]+=dp[j-i];
        }
        for(int j=1;j<=sum/2;j++){
            //cout<<dp[j]<<' ';
            }
    //cout<<endl;
        }
        cout<<dp[sum/2]/2;
    }
}