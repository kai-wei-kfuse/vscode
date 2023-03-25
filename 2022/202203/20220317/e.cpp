#include<iostream>
#include<algorithm>
typedef unsigned long long ll;
using namespace std;
struct xx{
    int t;ll v;
}a[5005];
ll dp[10005];
int main()
{
    int n;
    cin>>n;
    double tx;
    for(int i=1;i<=n;i++){
        cin>>tx>>a[i].v;
        tx=tx*10000+0.000005;
        a[i].t=tx;
        //cout<<a[i].t<<endl;
    }
    for(int i=1;i<=n;i++){
        //cout<<i<<'|';
        for(int j=10000;j>=a[i].t;j--){
            dp[j]=max(dp[j],dp[j-a[i].t]+a[i].v);
        }
    }
    cout<<dp[10000];
}