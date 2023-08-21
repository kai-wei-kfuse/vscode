#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>b(n+5);
        vector<vector<int>>mk(35);
        for(int i=1;i<n;i++)
        {
            cin>>b[i];
            int p=b[i];
            int cnt=0;
            while(p)
            {
                int x=p%2;
                p/=2;
                if(x==1)
                mk[cnt].push_back(i);
                cnt++;
            }
        }
        vector<int>num;
        k--;
        int fg=0;
        for(int j=0;j<30;j++)
        {
            if(mk[j].size()==0)
            {
                int x=k%2;
                num.push_back(x);
                k/=2;
            }else
            {
                int gkd=-1;
                //第一个1满足
                int o=(1<<(j+1));
                if(o<=b[mk[j][0]])
                {
                    gkd=1;
                }
                //第二个1满足或只有一个1
                if(mk[j].size()==1||o<=b[mk[j][1]])
                {
                    
                    if(gkd==1)
                    {
                        gkd=2;
                    }else
                    {
                        gkd=0;
                    }
                }
                if(gkd==-1)
                {
                    fg=1;
                    break;
                }
                if(gkd==0)
                {
                    num.push_back(0);
                }else if(gkd==1)
                {
                    num.push_back(1);
                }else if(gkd==2)
                {
                    int x=k%2;
                    num.push_back(x);
                    k/=2;                    
                }
            }
        }
        if(fg)
        {
            cout<<-1<<endl;
            continue;
        }
        if(k>0)
        {
            while(k)
            {
                int x=k%2;
                k/=2;
                num.push_back(x);
            }
        }
        int ans=0;
        for(int i=num.size()-1;i>=0;i--)
        {
            ans=ans*2+num[i];
        }
        vector<int>sum;
        sum.push_back(ans);
        for(int i=1;i<n;i++)
        {
            ans=ans^b[i];
            sum.push_back(ans);
        }
        int o=1<<30;
        fg=0;
        for(auto it:sum)
        {
            if(it>=o)
            {
                fg=1;
                break;
            }
        }
        if(fg)
        {
            cout<<-1<<endl;
        }else
        {
            for(auto it:sum)
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }
}