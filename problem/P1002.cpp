#include<iostream>//过河卒
using namespace std;
#define maxn 25
long long ans[maxn][maxn]={0};
int crtl[maxn][maxn]={0};
int xx[]={-1,-2,-2,-1,1,2,2,1};
int yy[]={-2,-1,1,2,2,1,-1,-2};
int main()
{
    int x,y,xh,yh;
    cin>>x>>y>>xh>>yh;
    for(int i=0;i<8;i++)
    {
        int X=xh+xx[i];
        int Y=yh+yy[i];
        if(X>=0&&Y>=0&&X<=x&&Y<=y)
        crtl[X][Y]=1;
    }
    crtl[xh][yh]=1;
    ans[0][0]=1;
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            if(crtl[i][j]==1)
            {
                //printf("%3d ",-1);
                continue;
            }
            else if(i==0)ans[i][j]+=ans[i][j-1];
            else if(j==0)ans[i][j]+=ans[i-1][j];
            else
            ans[i][j]=ans[i-1][j]+ans[i][j-1];
            //printf("%3d ",ans[i][j]);
        }
        //cout<<endl;
    }
    cout<<ans[x][y];
    return 0;
}