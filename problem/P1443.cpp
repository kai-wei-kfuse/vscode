#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int n,m,sx,sy;
int ans[410][410];
struct horse{
    int x,y;
};
queue < horse > Q;
int xx[]={-1,-2,-2,-1,1,2,2,1};
int yy[]={-2,-1,1,2,2,1,-1,-2};
int main()
{
    cin>>n>>m>>sx>>sy;
    memset(ans,-1,sizeof(ans));
    Q.push((horse){sx,sy});
    ans[sx][sy]=0;
    while(!Q.empty())
    {
        int x=Q.front().x;
        int y=Q.front().y;
        for(int i=0;i<8;i++)
        {
            int X=x+xx[i];
            int Y=y+yy[i];
            if(ans[X][Y]==-1 && X>=1 && Y>=1 && X<=n && Y<=m )
             {
            ans[X][Y]=ans[x][y]+1;// 步数加一
            Q.push((horse){X,Y});
             } 
        }
        Q.pop();
    }
    for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++)
    {
        printf("%-5d",ans[i][j]);
    }
    cout<<endl;}
    return 0;
}