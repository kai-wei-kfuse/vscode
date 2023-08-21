#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n+1);
        map<int,int>mp;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            mp[x]++;
        }
        int q;
        cin>>q;
        vector<int>v;
        for(int i=1;i<=q;i++)
        {
            int x,y;
            cin>>x>>y;
            if(x*x-4*y==0)
            {
                if(x%2==0)
                {
                    x/=2;
                    if(mp[x]>1)
                    {
                        v.push_back(mp[x]*(mp[x]-1)/2);
                    }else
                    {
                        v.push_back(0);
                    }
                }else
                {
                    v.push_back(0);
                }
            }else if(x*x-4*y>0)
            {
                int l=-1e10,r=x/2;
                if(x<0)
                {
                    if(x&1)
                    {
                        r--;
                    }
                }
                while(l<r)
                {
                    int mid=(l+r+1);
                    if(mid&1)
                    {
                        if(mid>=0) mid/=2;
                        else mid=mid/2-1;
                    }else
                    {
                        mid/=2;
                    }
                    if(mid*mid-mid*x+y==0)
                    {
                        l=mid;
                        break;
                    }
                    if(mid*mid-mid*x+y>=0)
                    {
                        l=mid;
                    }else
                    {
                        r=mid-1;
                    }
                }
                if(l*l-l*x+y==0)
                {
                    v.push_back(mp[l]*mp[x-l]);
                }else
                {
                    v.push_back(0);
                }
            }else
            {
                v.push_back(0);
            }
        }
        assert(v.size()==q);
        for(auto it:v)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
/*
1
6
1 4 -2 3 3 3
3
2 -8
*/