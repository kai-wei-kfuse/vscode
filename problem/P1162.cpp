#include<iostream>//广搜模板(队列STL)填涂颜色
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
//思路：广搜把为零的点全部标记为1（在1圈里面的就搜不到），然后没标记过的点（且不为1）输出的时候输出为2
int block[40][40];
bool vis[41][41];
struct color{
    int x,y;
};
int xx[]={-1,0,1,0};//循环方向
int yy[]={0,1,0,-1};
queue < color > Q;//创建队列
int main()
{
    int n;
    cin>>n;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>block[i][j];//从(1,1)开始输入矩阵
        }
        //从（0,0）开始搜索，因此在输入的矩阵外边有一圈0
    Q.push((color){0,0});//把(0,0)压入队列
    while(!Q.empty())
    {
        int l=0;
        for(int k=0;k<4;k++){//循环遍历四个方向
        int x=Q.front().x+xx[k];
        int y=Q.front().y+yy[k];
        if(block[x][y]==0 && x>=0 && y>=0 && x<=n+1 && y<=n+1 && vis[x][y]==0)
            {//注意边界条件！！！（且目标点没有被访问过，数组vis记录）
                Q.push((color){x,y});  
                vis[x][y]=1;//点符合条件，则压入队列,并且标记这个点
            }
        }
        Q.pop();//4个方向遍历完了就删除这个点
    } 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
         {
            if(vis[i][j]==0 && block[i][j]==0)
            cout<<"2"<<" ";
            else
            cout<<block[i][j]<<" ";
         }
         cout<<endl;
    }
    return 0;
}