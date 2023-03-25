#include<iostream>//阶乘之和（高精加+高精乘的应用）
#include<cstdio>//不重载运算符
#include<cstring>//高精加乘
using namespace std;
int sum[120],num[120];//目测结果不大于100位
int C1[120];
void mui(int a[],int b)//高精乘，结果储存在a里面
{
    int jw=0;
    for(int i=1;i<=120;i++)//比较暴力，直接这个数组遍历，而不是看数字长度
    {
        a[i]=a[i]*b+jw;
        jw=a[i]/10;
        a[i]%=10;
    }
}
void pluss(int a[],int b[])//高精加
{
    int jw=0;//进位
    for(int i=1;i<=120;i++)
        {
            a[i]=a[i]+b[i]+jw;//a+b再加上一位的进位
            jw=a[i]/10;//求进位
            a[i]%=10;//已经进位了，所以本位只保留个位
        }
}
int main()
{
    int n;
    cin>>n;
    num[1]=1;
    for(int i=1;i<=n;i++)//求阶乘
    {
        mui(num,i);
        pluss(sum,num);
    }
    bool flag=0;//输出：由于个位在右边（如“233”）而数组下标1是数的最高位（变成{3,3,2,0,0....}，所以要反向输出
    for(int i=120;i>0;i--)
    {
        if(sum[i]!=0)flag=1;//不能把多余的0输出，所以用flag标记(如数组{3,3,2,0,0....})一旦0结束就开始输出
        if(flag)
         cout<<sum[i];
    }
}