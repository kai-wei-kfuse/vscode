#include<bits/stdc++.h>
using namespace std;
int a[500][500];
priority_queue<int>q;
int vis[500];
int o[]={1,0,-1,0};
int p[]={0,1,0,-1};
int r,c;
int cnt=0;
map<int, pair<int, int>> mp;
void sol(int x,int y) 
{
    cnt++;
    q.push(a[x][y]);
    for(int i=0;i<2;i++)
    {
        if(x+o[i]>0&&x+o[i]<=r&&y+p[i]>0&&y+p[i]<=r)
        {
            if(a[x][y]<=a[x+o[i]][y+p[i]])
            {
                q.push(a[x+o[i]][y+p[i]]);
            }
        }
    }
    if(q.size()>0)
    {
        int p=q.top();
        q.pop();
        sol(mp[p].first,mp[p].second);
    }

}
int main()
{
    int r,c;
    cin>>r>>c;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cin>>a[i][j];
            mp[a[i][j]] = {i, j};
        }
    }
    int minn=-1e9;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            sol(i,j);
            minn=max(minn,cnt);
            cnt=0;
            while(q.size())
            {
                q.pop();
            }
        }
    }
    
}