#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100001;
signed main()
{
    int n;
    cin>>n;
    vector<int>a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    
    vector<int>num[N];
    set<int>se;
    se.insert(1);
    num[1].push_back(1);
    for(int i=2;i<=n;i++)
    {
        int ans=i;
        num[i].push_back(i);
        for(int j=2;;j++)
        {
            ans*=i;
            if(ans>n)
            {
                break;
            }
            num[i].push_back(ans);
            se.insert(ans);
        }   
        
    }
    cout<<"gg"<<endl;
    set<int>xx;
    for(int i=1;i<=n;i++)
    {
        if(!se.count(i))
        {
            xx.insert(i);
        }
    }
    
    int ans = 0;
    for(auto it:xx)
    {
    cout<<"g"<<endl;
        int maxn = 0;
        int cur = num[it].size();
        for (int i = 0; i < (1 << cur);i++)
        {
            int mm = 0;
            map<int,int> mp;
            for (int j = 0; j < cur;j++)
            {
                
                if(j&1)
                {
                    mp[i] = 1;
                }
            }
            for(auto x:mp)
            {
                mm += a[x.first];
                int temp = x.first*x.first;
                int factor = x.first;
                while(temp<=n)
                {
                    if(mp[temp]==1)
                        mm -= b[temp];
                    temp *= factor;
                }
            }
            maxn = max(maxn,mm);
        }
        ans += maxn;
    }
    cout << ans << endl;
}