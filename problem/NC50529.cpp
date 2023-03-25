#include<iostream>
using namespace std;
int n,m;
int a[10002];
int b[10002];
int ans=INT_MIN;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=b[i-1]+a[i];
    }
    //for(int i=1;i<=n;i++)cout<<b[i]<<' ';
    int head=1,tail=1;
    for(int i=1;i<=n;i++){
        while(head<=tail && head+m<i)head++;
        ans=max(ans,b[i]-b[head]);
        while(head<=tail && b[tail]>b[i])tail--;
        tail=i;
    }
    cout<<ans;
}