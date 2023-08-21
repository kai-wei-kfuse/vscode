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
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        vector<int>b=a;
        sort(b.begin()+1,b.end());
        vector<int>suf(n+2),pre(n+1);
        for(int i=1;i<=n;i++)
        {
            pre[i]=pre[i-1]+b[i];
        }
        for(int j=n;j>=1;j--)
        {
            suf[j]=suf[j+1]+b[j];
        }
        
        for(int i=1;i<=n;i++)
        {
            int ans=0;
            int p=lower_bound(b.begin()+1,b.end(),a[i])-b.begin();
            ans=a[i]*(p-1)-pre[p-1]+p-1;
            ans+=suf[p]-a[i]*(n-p+1)+n-p+1;
            cout<<ans<<" ";
        }   
        cout<<endl;

    }
}