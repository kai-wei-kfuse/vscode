#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int t,n,m,x,y,all,sums=1;
int xx[]={2,2,1,-1,-2,-2,-1,1};
int yy[]={-1,1,2,2,1,-1,-2,-2};
bool vis[11][11];
int sum=0;
void dfs(int x,int y)
{
    if(sums==all){
        sum++;
        return;
    }
    for(int i=0;i<8;i++){
        int X=x+xx[i];
        int Y=y+yy[i];
        if(X>=0 && Y>=0 && X<n && Y<m && vis[X][Y]==0){
            vis[X][Y]=1;
            sums++;
            dfs(X,Y);
            vis[X][Y]=0;
            sums--;
        }
    }
    return;
}
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++){
    sum=0;
    memset(vis,0,sizeof(vis));
    cin>>n>>m>>x>>y;
    all=n*m;
    vis[x][y]=1;
    dfs(x,y);
    cout<<sum<<endl;
    }
}