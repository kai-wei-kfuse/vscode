#include<bits/stdc++.h>//深搜 八皇后
using namespace std;
int ans=0,n,a[100],b1[100],b2[100],b3[100];//b1是列的标记，b2是对角线的标记，b3是副对角线的标记
void dfs(int x);
int main()
{
    cin>>n;
    dfs(0);
    cout<<ans;
    return 0;
}
void dfs(int x)
{
    if(x==n)
    {
        ans++;
        if(ans<=3)
        {
        for(int i=0;i<n;i++)
        cout<<a[i]+1<<" ";
        cout<<endl;
        }
    }
    for(int y=0;y<n;y++)
    {
        //for(k=0;k<x;k++)
        //if(a[k]==i || abs(x-k)==abs(i-a[k]))break;
        //if(k==x)
        if(b1[y]==0&&b2[x+y]==0&&b3[x-y+15]==0)
        {
            a[x]=y;
            b1[y]=1; b2[x+y]=1;  b3[x-y+15]=1;//x+y:
            dfs(x+1);
            b1[y]=0 ; b2[x+y]=0;  b3[x-y+15]=0;//这种矩阵的判断条件可以设一个标记数组
        }
    }
    return ;
}
