#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
const int N = 5e6+7;
const int mod = 998244353;
multiset<int> se[N]; //鍘熷浘
vector<int> cir;
stack<int> st;
bool vis[N];
int dfn[N];
#define IOS ios::sync_with_stdio(0),cin.tie(0)
void dfs(int x,int num)
{
    if(vis[x]!=0)
    {
        cir.push_back(num - dfn[x]);
        return;
    }
    dfn[x] = num;
    vis[x] = 1;
    for(auto i:se[x])
    {
        se[i].erase(x);
        dfs(i, num + 1);
    }
}
ll qpow(ll x,ll n)
{
    ll base=1;
    while(n)
    {
        if(n&1)
        {
            base=base*x%mod;
        }
        n>>=1;
        x=x*x%mod;
    }
    return base;
}
ll t[N];
void init()
{
    t[0]=1;
    for(int i=1;i<N;i++)
    {
        t[i]=t[i-1]*2%mod;
/*         cout<<t[i]<<" "; */
    }
}
signed main()
{
    IOS;
    init();
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        se[u].insert(v);
        se[v].insert(u);
    }
    if(m>0)
    dfs(u,1);
    ll ans=0;
    if(cir.size())
    for(auto i:cir)
    {
        ans=ans+i;
    }
    ll res=m-ans;
    ll tot=1;
    if(cir.size())
    for(auto it:cir)
    {
        tot=tot*(t[it]-1)%mod;
    }
    cout<<tot*qpow(2,res)%mod<<endl;

}