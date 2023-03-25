#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
int xx[]={-1,0,1,0};
int yy[]={0,1,0,-1};
bool maps[1001][1001];
int vis[1001][1001]={0};
int ans[1000010];
int cnt=0;
struct xy{
    int x,y;
};
int c=1;
void bfs(int x,int y)
{
    queue < xy > Q;
    Q.push((xy){x,y});
    vis[x][y]=c;
    while(!Q.empty())
        {
            for(int i=0;i<4;i++)
            {
                int X=Q.front().x+xx[i];
                int Y=Q.front().y+yy[i];
                if(X>=1 && Y>=1 && X<=n && Y<=n && vis[X][Y]==0 && maps[X][Y]!=maps[Q.front().x][Q.front().y])
                {
                    Q.push((xy){X,Y});
                    vis[X][Y]=c;
                }
            }
            Q.pop();
            cnt++;
        }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char a;
            cin>>a;
            if(a=='0')
            maps[i][j]=0;
            else
            maps[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(!vis[i][j]){
                c++;
                bfs(i,j);
                ans[c]=cnt;
                cnt=0;
            }
        }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
        cout<<vis[i][j]<<' ';
        }
        cout<<endl;
    }*/
     for(int i=1;i<=m;i++)
    {
        int sum=0;
        int x;
        int y;
        cin>>x>>y; 
        int now=vis[x][y];
        cout<<ans[now]<<endl;
    }
}