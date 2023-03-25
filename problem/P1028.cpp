#include<iostream>//记忆化搜索
#include<cstring>//数的计算
using namespace std;
int mem[1010];//数组记录每次算的结果
int n;
int jisuan(int n)
{
    int ans=1;//种数初始为1，因为什么都不干就算1种,比如8本身
    if(mem[n]!=-1)return mem[n];//不可以写（!n）,if的括号里只能是bool，-1不可以
    for(int i=1;i<=n/2;i++)//遍历小于等于n一半的数如（n=8,就会遍历1,2,3,4)
    {
        mem[i]=jisuan(i);
        ans+=mem[i];//8的总数=1的总数+2的总数+3的总数+4的总数
    }
    return mem[n]=ans;//返回 同时记忆
}
int main ()
{
    cin>>n;
    memset(mem,-1,sizeof(mem));
    mem[1]=1;
    cout<<jisuan(n);
    return 0;
}