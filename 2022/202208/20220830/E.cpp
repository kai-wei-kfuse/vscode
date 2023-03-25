#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
bool cmp(P a,P b)
{
    if(a.first==b.first)
    {
        return a.second > b.second;
    }
    return a.first>b.first;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        double p;
        cin>>n>>p;
        p=p/100.0;
        vector<P>ve;
        multiset<int>se,see;
        for(int i=1;i<=n;i++)
        {
            int x,y;
            cin>>x>>y;
            ve.push_back({x,y});
            se.insert(x);
        }
        sort(ve.begin(),ve.end(),cmp);
        int i = 0;
        for (; i < ve.size();i++)
        {
            if(see.size())
            {
                auto it = *see.end();
                cout << it << " ";
                if((it)>(ve[i].first))
                {
                    break;
                }
            }
            se.erase(ve[i].first);
            see.insert(ve[i].second);
        }
/*         cout << maxn << endl; */
    }
}