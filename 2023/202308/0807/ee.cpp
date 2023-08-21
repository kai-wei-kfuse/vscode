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
        vector<int>ve(n+1),ve1(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>ve[i];
            ve1[i]=ve[i];
        }
        sort(ve1.begin()+1,ve1.end());
        vector<int>suf(n+2),pre(n+2);
        for(int j=n;j>=1;j--)
        {
            suf[j]=suf[j+1]+ve1[j];
        }
        for(int i=1;i<=n;i++)
        {
            pre[i]=pre[i-1]+ve1[i];
        }
        
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int x=lower_bound(ve1.begin()+1,ve1.end(),ve[i])-ve1.begin();
            ans=(ve[i]+1)*(x-1)-pre[x-1];
            ans+=suf[x]-(ve[i]-1)*(n-x+1);
            cout<<ans<<" ";
        }   
        cout<<endl;
    }
}