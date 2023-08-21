#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        set<int>se;
        map<int ,int>mp;
        for(int i=2;i<=n;i++)
        {
            mp[i]=1;
            se.insert(i+1);
        }
        a[0]=1;
        for(int i=1;i<n;i++)
        {
            if(mp[a[i-1]*2]==1)
            {   
                a[i]=a[i-1]*2;
                mp[a[i-1]*2]=0;
                se.erase(a[i-1]*2);
            }else
            {
                a[i]=*se.begin();
                mp[*se.begin()]=0;
                auto x=se.find(*se.begin());
                se.erase(x);
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

}