#include<iostream>//前缀和
#include<algorithm>
using namespace std;
int a[2000002];
int mins=0x7fffffff;
int ans=0x80000000;
int main()
{
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]=a[i-1]+a[i];
        }
    for(int i=1;i<=n;i++){
        mins=min(mins,a[i-1]);
        ans=max(ans,a[i]-mins);
    }
    cout<<ans;
}