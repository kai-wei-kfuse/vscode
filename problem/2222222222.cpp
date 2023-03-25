#include<stdio.h>
#include<iostream>
#include<cstring>
#define int long long
using namespace std;
const int mod = 1000000007;
int fa[2000015];
int mu[2000015];
int a[2000015];
int n,m,sum;
int has[2000015];
string s;
int find(int x)
{
    return x==fa[x]?x:fa[x] = find(fa[x]);
}
void mul(int x,int y)
{
 mu[find(x)] = (mu[find(x)]*mu[find(y)])%mod;
    mu[find(x)]%=mod;
    fa[find(y)] = find(x);
}
int qmi(int a, int b, int p)
{
    int res = 1 % p;
    a %= p;
    while (b > 0)
    {
    if(b & 1) 
    res = res * a % p;
    a = a * a % p;
    b >>= 1;
    }
    return res;
}
int main()
{
    cin>>n>>m;
    for(int i = 1;i<=n+10;++i)
        fa[i] = i;
    cin>>s;
    for(int i = 1;i<=n;++i)
    {
        cin>>a[i];
        a[i]%=mod;
        mu[i] = a[i];
        if(i>1&&s[i-2]=='*')
            mul(i,i-1);
    }
    for(int i = 1;i<=n;++i)
    {
        if(!has[find(i)])
        {
            sum = (sum+mu[find(i)])%mod;
            has[find(i)] = 1;
           // sum%=mod;
        }
    }
    for(int i = 1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        int c = y-a[x];
        int xx = find(x);
        //sum=(sum+mod)%mod;
        sum = (sum+mod+(c*((mu[xx]*qmi(a[x],mod-2,mod))%mod)%mod)%mod)%mod;
        cout<<sum%mod<<endl;
        mu[xx] = (mu[xx]*qmi(a[x],mod-2,mod)%mod)*y%mod;
        a[x] = y%mod;
    }
}
