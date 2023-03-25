#include<bits/stdc++.h>//单词方阵
using namespace std;
bool vis[110][110];
char a[110][110];
int n;
int X[]={1,1,1,0,0,-1,-1,-1};
int Y[]={1,0,-1,1,-1,1,0,-1};
string eq="yizhong";
void dfs(int x,int y)
{
    for(int i=0;i<8;i++)//八个方向
    {
        int flag=0;
        for(int j=0;j<7;j++){//其中一个方向判断单词
            int xx=x-j*X[i];
            int yy=y-j*Y[i];
            if(a[xx][yy] != eq[j] || xx<=0 || xx>n || yy<=0 || yy>n)
            {
                flag=1;
            }   
        }
        if(flag==0)
        for(int j=0;j<7;j++)
        {
            int xx=x-j*X[i];
            int yy=y-j*Y[i];
        vis[xx][yy]=1;
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j]=='y')
            {
                dfs(i,j);
            }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        {
            if(!vis[i][j])
                cout<<'*';
            else
                cout<<a[i][j];}
    cout<<endl;
}
    return 0;
}