#include<iostream>//台阶问题（递推）
using namespace std;
int a[1000010]={1};
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<i;j++)
        a[i]+=a[j];
        a[i]%=100003;
        //cout<<a[i]<<" "<<"\n";
    }
    for(int i=k+1;i<=n;i++)
    {
        for(int j=i;j>=i-k;j--)
        a[i]+=a[j];
        a[i]%=100003;
        //cout<<a[i]<<" "<<"\n";
    }
    cout<<a[n];
    return 0;
}