#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n,m;
struct xy{
    int x,y;
}k;
int xx[]={-1,0,1,0};
int yy[]={0,1,0,-1};
bool vis[21][21];
char a[22][22];
int main()
{
    while(1)
    {
        memset(vis,0,sizeof(vis));
        cin>>m;
        cin>>n;
        if(m>0 && n>0 )
        {
        int sum=1;
        queue < xy > Q;
        for(int i=0;i<n;i++)//n代表行数，m代表列
        {
            cin>>a[i];
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='@')
                {
                    k.x=i;
                    k.y=j;
                    Q.push(k);
                    vis[i][j]=1;
                }
            }
        }
        while(!Q.empty())
        {
            for(int i=0;i<4;i++)
            {
                int X=Q.front().x+xx[i];
                int Y=Q.front().y+yy[i];
                if(X>=0 && Y>=0 && X<n && Y<m && a[X][Y]=='.' && vis[X][Y]==0)
                {
                    sum++;
                    vis[X][Y]=1;
                    k.x=X;
                    k.y=Y;
                    Q.push(k);
                }
            }
            Q.pop();    
        }
        if(m>0)
        cout<<sum<<endl;
        }
        else return 0;
    }
}
