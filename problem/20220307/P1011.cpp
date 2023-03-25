#include<iostream>
using namespace std;
int f[22];
int asum[22];
int xsum[22];
int main()
{
    int a,n,m,x;
    cin>>a>>n>>m>>x;
    f[1]=1;f[2]=1;
    for(int i=3;i<=n;i++){
        f[i]=f[i-1]+f[i-2];
        anum[i]=f[i-2]+1;
        xnum[i]=xsum[i-1]+f[i-3];
    }
    int y=(m-a*snum[n])/xsum[n];
    cout<<a*anum[x]+y*xnum[x];
}