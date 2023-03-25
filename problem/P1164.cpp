#include<iostream>
using namespace std;
int val[102],dp[10002]={1};
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&val[i]);
    }
    cout<<' '<<'|';
    for(int i=1;i<=n;i++)cout<<i<<' ';
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<'|';
        for(int j=m;j>=val[i];j--){
            dp[j]+=dp[j-val[i]];
        }
        for(int j=1;j<=m;j++){
            cout<<dp[j]<<' ';
        }
        cout<<endl;
    }
    cout<<dp[m];
}