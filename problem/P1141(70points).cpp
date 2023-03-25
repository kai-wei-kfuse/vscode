#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n,m;
int xx[]={-1,0,1,0};
int yy[]={0,1,0,-1};
string a[1001];
int maps[1001][1001];
int vis[1001][1001]={0};
struct xy{
    int x,y;
};
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        memset(vis,0,sizeof(vis));
        int sum=1;
        int x;
        int y;
        cin>>x>>y;
        queue < xy > Q;
        Q.push((xy){x-1,y-1});
        vis[x-1][y-1]=1;
        while(!Q.empty())
        {
            for(int i=0;i<4;i++)
            {
                int X=Q.front().x+xx[i];
                int Y=Q.front().y+yy[i];
                if(a[Q.front().x][Q.front().y]=='1')
                {
                if(X>=0 && Y>=0 && X<=n && Y<=n && vis[X][Y]==0 && a[X][Y]=='0')
                {
                    Q.push((xy){X,Y});
                    vis[X][Y]=1;
                    sum++;
                }
                }
                else if(a[Q.front().x][Q.front().y]=='0')
                {
                if(X>=0 && Y>=0 && X<=n && Y<=n && vis[X][Y]==0 && a[X][Y]=='1')
                {
                    //cout<<'a';
                    Q.push((xy){X,Y});
                    vis[X][Y]=1;
                    sum++;
                }
                }
            }
            Q.pop();
        }
    cout<<sum<<endl;
    }
}