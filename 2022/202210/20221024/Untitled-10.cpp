#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
struct node{
    int w,r,s;
}t[11];
signed main()
{
    vector<pair<int,int>>v(11);
    for(int i=1;i<=10;i++)
    {
        cin>>v[i].fi>>v[i].se;
    }
    for(int i=1;i<=10;i++)
    {
        cin>>t[i].w>>t[i].r>>t[i].s;
    }
    int cnt=0;

    queue<int>q[11];
    for(int i=1;i<=10;i++)
    {
        int sum=t[i].w+t[i].r;
        if(cnt<t[i].s)
        {
            cnt+=v[i].fi;
            q[i].push(max(cnt,t[i].s));
            cnt+=v[i].se;
        }else if(cnt==t[i].s)
        {
            int temp = cnt + t[i].w;
            temp += v[i].fi;
            q[i].push(max(temp,cnt+sum));
            cnt = temp + v[i].se;
        }
        else
        {
            
            if((cnt-t[i].s)%(sum)==0)
            {
                int temp = cnt + t[i].w;
                temp += v[i].fi;
                q[i].push(max(temp,cnt+sum));   
                cnt=temp+v[i].se; 

            }else if((cnt-t[i].s)%(sum)>t[i].w)
            {

                int temp=cnt+v[i].fi;

                q[i].push(max(temp,cnt+sum-((cnt-t[i].s)%(sum))));
                cnt=temp+v[i].se;  
            }else
            {
                int temp=cnt+(t[i].w-(cnt-t[i].s)%(sum));
                temp+=v[i].fi;
                q[i].push(max(cnt+sum-((cnt-t[i].s)%(sum)),temp));
                cnt=temp+v[i].se;
            }
        }
        
/*         cout << cnt << endl; */
    }
    for(int i=1;i<=10;i++)
    {
        int xx = q[i].front();
        q[i].pop();
        int sum=t[i].w+t[i].r;
        if(cnt<xx)
        {
            cnt+=v[i].fi;
            q[i].push(max(cnt,xx));
            cnt+=v[i].se;
        }else if(cnt==xx)
        {
            int temp = cnt + t[i].w;
            temp += v[i].fi;
            q[i].push(max(temp,cnt+sum));
            cnt = temp + v[i].se;
        }
        else
        {
            
            if((cnt-xx)%(sum)==0)
            {
                int temp = cnt + t[i].w;
                temp += v[i].fi;
                q[i].push(max(temp,cnt+sum));   
                cnt=temp+v[i].se; 

            }else if((cnt-xx)%(sum)>t[i].w)
            {

                int temp=cnt+v[i].fi;

                q[i].push(max(temp,cnt+sum-((cnt-xx)%(sum))));
                cnt=temp+v[i].se;  
            }else
            {
                int temp=cnt+(t[i].w-(cnt-xx)%(sum));
                temp+=v[i].fi;
                q[i].push(max(cnt+sum-((cnt-xx)%(sum)),temp));
                cnt=temp+v[i].se;
            }
        }
        
/*         cout << cnt << endl; */
    }
    for(int i=1;i<=10;i++)
    {
        int xx = q[i].front();
        q[i].pop();
        int sum=t[i].w+t[i].r;
        if(cnt<xx)
        {
            cnt+=v[i].fi;
            q[i].push(max(cnt,xx));
            cnt+=v[i].se;
        }else if(cnt==xx)
        {
            int temp = cnt + t[i].w;
            temp += v[i].fi;
            q[i].push(max(temp,cnt+sum));
            cnt = temp + v[i].se;
        }
        else
        {
            
            if((cnt-xx)%(sum)==0)
            {
                int temp = cnt + t[i].w;
                temp += v[i].fi;
                q[i].push(max(temp,cnt+sum));   
                cnt=temp+v[i].se; 

            }else if((cnt-xx)%(sum)>t[i].w)
            {

                int temp=cnt+v[i].fi;

                q[i].push(max(temp,cnt+sum-((cnt-xx)%(sum))));
                cnt=temp+v[i].se;  
            }else
            {
                int temp=cnt+(t[i].w-(cnt-xx)%(sum));
                temp+=v[i].fi;
                q[i].push(max(cnt+sum-((cnt-xx)%(sum)),temp));
                cnt=temp+v[i].se;
            }
        }
        
/*         cout << cnt << endl; */
    }            
    cout<<cnt-v[10].se<<endl;
}