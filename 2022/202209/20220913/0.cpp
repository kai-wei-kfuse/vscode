#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int num=1;
int K;
vector<int>ff(1e5+7);
vector<int>ans(1e5+7);
int node=0;
void dfs(ll x)
{
    int sour = x;
    int fa=node;
    for (int i = 2; i <= x / i; i++)
    {
        if(x%i==0)
        {
            node++;
            ff[node]=fa;
            x = x / i;
            ans[node]=i;
            
            while (x % i == 0)
            {
                node++;
                //父亲
                ff[node]=node-1;
                x /= i;
                ans[node]=i;
                
            }
        }

    }
    if (x > 1)
    {
        ff[++node] = fa;
        ans[node] = 1;
        
        ans[fa]=sour;
        node++;
        dfs(x-1);
        ff[node]=node-1;
    }
    
}
int main()
{
    
    cin >> K;
    if (K == 1)
    {
        cout << 2 << endl;
        cout << 1 << endl;
        cout << 1 << " " << 2;
        return 0;
    }
    else if (K == 2)
    {
        cout << 2 << endl;
        cout << 1 << endl;
        cout << 1 << " " << 1;
        return 0;
    }
    node=1;
    dfs(K);
    cout<<node<<endl;
    for(int i=2;i<=node;i++)
    {
        cout<<ff[i]+1<<" ";
    }
    cout<<endl;
    for (int i = 1; i <= node;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout << endl;
    //-----对k质因数分解


    
}