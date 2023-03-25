#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+7;
vector<int>a(N+1);
bool chec(ll mid,ll n)
{
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<mid)
        {
            res+=mid-a[i];
        }
    }
    if(res<mid)
    {
        return true;
    }else
    {
        return false;
    }
}
int main()
{
    int t;
    cin>>t;
    int cnt = 0;
    while(t--)
    {
        cnt++;
        int n;
        cin>>n;
       
        for(int i=1;i<=n;i++) cin>>a[i],a[i]++;
        ll l=1,r=(ll)1e13;
        while(l<r)
        {
            ll mid=(l+r+1)/2;
            if(chec(mid,n))
            {
                l=mid;
            }else
            {
                r=mid-1;
            }
        }
        cout << "Case #" << cnt << ": ";
        cout<<l<<endl;
    }
}