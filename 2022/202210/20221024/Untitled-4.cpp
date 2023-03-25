#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4+7;
vector<int>e[N];
int sum[N];
int aa,bb;
int n;
void dfs(int x,int fa)
{
/*     cout << x << " " << fa << endl; */
    sum[x]=1;
    vector<int>p;
    for(auto it:e[x])
    {
        if(it!=fa)
        {
            dfs(it,x);
            sum[x]+=sum[it];
            p.push_back(sum[it]);
        }
    }
    p.push_back(n+1-sum[x]);
    sort(p.begin(),p.end());
/*     cout << "tim" << x << endl;
    for(auto it:p)
    {
        cout << it << " ";
    }
    cout << endl; */
    vector<int>q=p;
    for(int i=q.size()-2;i>=0;i--)
    {
        q[i]+=q[i+1];
    }
    int oo=0;
/*     for(auto it:q)
    {
        cout << it << " ";
    }
    cout << endl; */
    for(int i=0;i<p.size()-1;i++)
    {
        oo+=p[i]*q[i+1];
/*         cout << p[i] << " " << q[i + 1] << endl; */
    }
    if(p.size()==1)
    {
        if(oo>=aa)
        {
            oo=0;
            bb=0;
        }
    }else
    {
        if(oo>=aa)
        {
            aa=oo;
            bb=p[p.size()-1]*p[p.size()-2];
        }        
    }
/*     cout << oo << endl; */
}
signed main()
{

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(0,0);
/*     for (int i = 0; i <= n;i++)
    {
        cout << sum[i] << endl;
    } */
        cout << aa << " " << aa-bb << endl;
}