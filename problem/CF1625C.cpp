#include<iostream>
#include<cstring>
using namespace std;
int d[502];
int t[502];
int dp[502][502];
int main()
{
    int n,l,m;
    cin>>n>>l>>m;
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++){
        cin>>d[i];
    }
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    d[++n]=l;
    dp[1][1]=0;
    for(int i=2;i<=n;i++){
        //dp[i][1]=d[i]*t[1];
        for(int j=1;j<=i;j++){
            for(int k=1;k<i;k++){
                dp[i][j]=min(dp[i][j],dp[k][j-1]+(d[i]-d[k])*t[k]);
            }
            //cout<<dp[i][j]<<' ';
        }
        //cout<<endl;
    }
    int ans=0x3f3f3f3f;
    for(int i=n;i>=n-m;i--){
        ans=min(dp[n][i],ans);
    }
    cout<<ans;
}