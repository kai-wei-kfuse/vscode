#include<iostream>
using namespace std; 
int m,dp[1002],val[1002];
int main()
{
    cin>>m;
    for(int i=1;i<=m;i++){
        for(int j=1;j<i;j++){
            if(i%j==0)val[i]+=j;
        }
       // cout<<val[i]<<' ';
    }
   // cout<<endl;
    for(int i=1;i<=m;i++){
       // cout<<i<<'|';
        for(int j=m;j>=i;j--){
            dp[j]=max(dp[j],dp[j-i]+val[i]);
            //cout<<dp[j]<<' ';
        }
        //cout<<endl;
    }
    cout<<dp[m];
}