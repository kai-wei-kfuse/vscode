#include<iostream>//迷宫
#include<cstdio>
using namespace std;
int a[6][6],ans=0;
int x1,yy,x2,y2;
int n,m;
void dfs(int x,int y)
{
    if(x==x2&&y==y2)
    {
        ans++;
        return ;
    }
    if(y<m && !a[x][y+1])
    {
        a[x][y+1]=1;
        dfs(x,y+1);
        a[x][y+1]=0;
    }
    if(x<n && !a[x+1][y])
    {
        a[x+1][y]=1;
        dfs(x+1,y);
        a[x+1][y]=0;
        }
    if(x-1>0 && !a[x-1][y])
    {
        a[x-1][y]=1;
        dfs(x-1,y);
        a[x-1][y]=0;
        }
    if(y-1>0 && !a[x][y-1])
    {
        a[x][y-1]=1;
        dfs(x,y-1);
        a[x][y-1]=0;
        }
    return ;
}
int main()
{
    cin>>n>>m;
    //memset(a,0,sizeof(a));
    int block;
    cin>>block;
    cin>>x1>>yy>>x2>>y2;
    int X,Y;
    for(int i=1;i<=block;i++)
    {
        cin>>X>>Y;
        a[X][Y]=1;
    }
    a[x1][yy]=1;
    dfs(x1,yy);
    cout<<ans;
    return 0;
}
