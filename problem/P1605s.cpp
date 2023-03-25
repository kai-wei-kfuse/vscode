#include<iostream>//迷宫(复盘)
#include<cstdio>
using namespace std;
int xx[]={-1,0,1,0};
int yy[]={0,1,0,-1};
int a[10][10]={0};
int xs,ys,x2,y2;
int sum=0;
int n,m,t;
void dfs(int x,int y)
{
    if(x==x2&&y==y2)
    {
        sum++;
        return;
    }
    else
    for(int i=0;i<4;i++)
    {
        int X=x+xx[i];
        int Y=y+yy[i];
        if(X<=n&&Y<=m&&X>=1&&Y>=1&&a[X][Y]==0)
        {
            a[X][Y]=1;
            dfs(X,Y);
            a[X][Y]=0;
        }
    }
    return ;
}
int main()
{
    cin>>n>>m>>t;
    cin>>xs>>ys>>x2>>y2;
    for(int i=1;i<=t;i++)
    {
        int xc,yc;
        cin>>xc>>yc;
        a[xc][yc]=1;//1代表不能走
    }
    int x=xs,y=ys;
    a[xs][ys]=1;
    dfs(x,y);
    cout<<sum;
}