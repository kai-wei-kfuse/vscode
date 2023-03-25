#include<iostream>
#include<algorithm>
using namespace std;
int m[102];
int p[102];
int prevs[102];
int dp[102];
int main()
{
    int t;
    scanf("%d",&t);
    int n,k;
    for(int i=1;i<=t;i++){
        scanf("%d %d",&n,&k);
        for(int j=1;j<=n;j++){
            scanf("%d",&m[j]);
        }
        for(int j=1;j<=n;j++){
            scanf("%d",&p[j]);
            dp[j]=p[j];
        }
        for(int j=1;j<=n;j++){
            for(int l=1;l<=n;l++){
                if(m[l]<m[j]-k)
                dp[j]=max(dp[j],dp[l]+p[j]);
                //cout<<dp[j]<<' ';
            }
        }
        cout<<*max_element(dp+1,dp+n+1)<<endl;
    }
}