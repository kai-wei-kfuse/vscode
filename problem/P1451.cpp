#include<iostream>
#include<cstdio>
using namespace std;
char a[120][120];
int xx[]={-1,0,1,0};
int yy[]={0,1,0,-1};
bool vis[120][120];
int n,m,sum=0;
void dfs(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int X=x+xx[i];
        int Y=y+yy[i];
        if(a[X][Y]!= '0'&& vis[X][Y]==0 && X>=0 && Y>=0 && X<n && Y<m)
        {
            vis[X][Y]=1;
            dfs(X,Y);
        }
    }
    return ;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(a[i][j]!='0' && vis[i][j]==0)
            {
                vis[i][j]=1;
                dfs(i,j);
                sum++;
            }
        }
    cout<<sum;
    return 0;
}