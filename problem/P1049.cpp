#include<iostream>
using namespace std;
int v[32],dp[20002];
int main()
{
    int V,n;
    cin>>V>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=V;j>=v[i];j--){
            dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
        }
    }
    cout<<V-dp[V];
}