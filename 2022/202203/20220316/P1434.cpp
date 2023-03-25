#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int mp[102][102];
int vis[102][102];
int r,c;
int xx[]={-1,0,1,0};
int yy[]={0,1,0,-1};
int ans=0;
int dfs(int x,int y){
    if(vis[x][y])return vis[x][y];
    //ans=max(ans,s);
    //if(vis[x][y])
    int maxn=1;
    for(int i=0;i<4;i++){
        int X=x+xx[i];int Y=y+yy[i];
        if(X>=1 && Y>=1 && X<=r && Y<=c){
            if(mp[x][y]>mp[X][Y]){
                maxn=max(maxn,dfs(X,Y)+1);
            }
        }
    }
    return vis[x][y]=maxn;
}
int main()
{
    cin>>r>>c;
    //memset(vis,1,sizeof(vis));
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>mp[i][j];
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            ans=max(ans,dfs(i,j));
        }
    }
    cout<<ans;
}