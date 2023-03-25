#include<bits/stdc++.h>
using namespace std;
char x[105][105];
int ans=0;
int q[]={0,0,1,-1,1,1,-1,-1};
int p[]={1,-1,0,0,1,-1,1,-1};
int vis[105][105];
int n, m;
void dfs(int a,int b)
{
    vis[a][b]=1;
    for(int i=0;i<8;i++)
    {
        int xx=a+q[i],yy=b+p[i];
        if(xx>0&&xx<=n&&yy>0&&yy<=m&&!vis[xx][yy]&&x[xx][yy]=='#')
        {
            dfs(xx,yy);
        }
    }
    
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>x[i][j];
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!vis[i][j]&&x[i][j]=='#')
            {
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans<<endl;
}