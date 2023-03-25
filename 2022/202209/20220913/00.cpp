#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
vector<int>e[N];
int node=1;
int ff[N];
void dfs(int x,int fa)
{
    if(x==1)
    {
        return;
    }else if(x==2)
    {
        e[fa].push_back(++node);
        ff[node] = fa;
        return;
    }
    e[fa].push_back(++node);
    ff[node] = fa;
    e[node].push_back(++node);
    ff[node] = node-1;
    e[fa].push_back(++node);
    ff[node] = fa;
    dfs(x / 2, node);
}
int sum[N];
void dfs2(int x,int fa)
{
    sum[x] = 1;
    for(auto it:e[x])
    {
        if(it==fa)
            continue;
        dfs2(it, x);
        sum[x] += sum[it];

    }
    if(e[x].size()==1)
    {
        sum[x] = 1;
    }
}
int main()
{

    int n;
    cin>>n;
    if (n == 1)
    {
        cout << 2 << endl;
        cout << 1 << endl;
        cout << 1 << " " << 2;
        return 0;
    }
    else if (n == 2)
    {
        cout << 2 << endl;
        cout << 1 << endl;
        cout << 1 << " " << 1;
        return 0;
    }    
    int fa=1;
    dfs(n, 1);
    cout << node << endl;
    for (int i = 2; i <= node;i++)
    {
        cout << ff[i] << " ";
    }
    cout << endl;
    dfs2(1, fa);
    for (int i = 1; i <= node;i++)
    {
        cout<<sum[i]<<" ";
    }
}