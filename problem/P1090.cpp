#include<iostream>//合并果子
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[10001],b[10001];
int main()
{
    memset(b,127,sizeof(b));
    memset(a,127,sizeof(a));
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int i=0,j=0,l=0,sum=0;
    for(int k=1;k<n;k++)
    {
        int mid;
        mid=a[i]<b[j]?a[i++]:b[j++];
        mid+=a[i]<b[j]?a[i++]:b[j++];
        b[l++]=mid;
        sum+=mid;
    }
    cout<<sum;
    return 0;
}