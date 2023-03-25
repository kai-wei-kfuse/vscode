#include<bits/stdc++.h>//深搜
using namespace std;
int a[20],n=16,ans=0;
int b1[5][5],b2[5][5],b3[5][5];
void dfs(int x)//x表示递归层数
{
    if(x>n)
    {
        ans++;//ans表示结果数量
        for(int i=1;i<=n;i++)
        {
            cout<<a[i]<<" ";
            if(i%4==0)cout<<endl;
        }
        cout<<endl;//用来输出结果
    }
    int row=(x-1)/4+1;//通过推导，由第几个空计算出这个空是第几行
    int col=(x-1)%4+1;//第几列
    int block=(row-1)/2*2+(col-1)/2+1;//第几个中格子（四个为一中格）
    //数独，每一行每一列每一中格不能有重复数字
    for(int i=1;i<=4;i++)
    {
        if(b1[row][i]==0&&b2[col][i]==0&&b3[block][i]==0)
        //如果这个数字在同一行同一列同一个中格没有被填过就可以用
        {
            a[x]=i;//填数
            b1[row][i]=b2[col][i]=b3[block][i]=1;//填了数就要占位
            dfs(x+1);//下一层
            b1[row][i]=b2[col][i]=b3[block][i]=0;//递归完了，代表这种情况已经完成，取消占位
        }
    }
}
int main()
{
    dfs(1);
    cout<<ans;
    return 0;
}