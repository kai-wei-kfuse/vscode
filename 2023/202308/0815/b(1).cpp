#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,d;
        cin>>n>>m>>d;
        vector<pair<int,int> >a;
        a.push_back({1,0});
        a.push_back({n+1,0});
        for(int i=1;i<=m;i++)
        {
            int x;cin>>x;
            a.push_back({x,i});
        }
        sort(a.begin(),a.end());

        int cur=-1;
        int res=0;
        for(int i=1;i<a.size()-1;i++)
        {
            int x=a[i-1].first;
            int y=a[i].first;
            int z=a[i+1].first;
            int o=(y-x+d-1)/d;
            int p=(z-y+d-1)/d;
            int q=(z-x+d-1)/d;
            if(q<o+p)
            {
                cur=a[i].second;
                res++;
            }
        }
        int ans=0;
        for(int i=1;i<a.size();i++)
        {
            ans+=(a[i].first-a[i-1].first+d-1)/d;
        }
/*         cout<<endl;
        cout<<ans<<endl; */
 /*        cout<<cur<<endl; */
        if(cur!=-1)
        {
            cout<<ans-1<<" ";
            cout<<res<<endl;
        }else
        {
            cout<<ans<<" "<<m<<endl;
        }
    }
}