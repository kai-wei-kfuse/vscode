#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int dp[1002];
int a[1002];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp[i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[i]>a[j])
            dp[i]=max(dp[j]+1,dp[i]);
        }
    }
    cout<<*max_element(dp+1,dp+n+1);
}