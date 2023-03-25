#include<bits/stdc++.h>//高精乘
using namespace std;
int A[4010],B[4010],C[4010];
int main()
{
    string a,b;
    cin>>a>>b;
    int lena=a.length();
    int lenb=b.length();
    int len=lena+lenb;
    for(int i=lena-1;i>=0;i--)
        A[lena-i]=a[i]-'0';
    for(int i=lenb-1;i>=0;i--)
        B[lenb-i]=b[i]-'0';//和高精加一样，把字符转为int数组，
        //同样要倒过来字符数组最高位是个位，把他变成int数组第一位
    for(int i=1;i<=lena;i++)
        for(int j=1;j<=lenb;j++)
        C[i+j-1]+=A[i]*B[j];//这里开始乘，根据乘法运算，要两数的每个数枚举相乘，而且
        //规律是第i位和第j位相乘，得到的数在i+j-1处
    for(int i=1;i<=len;i++)
    {
        C[i+1]+=C[i]/10;
        C[i]%=10;//和高精加一样，模拟进位
    }
    string ans;
    //法一
    while(!C[len])len--;
    for(int i=max(len,1);i>0;i--){//为了防止乘数是零，如果是0，len就变成零了
        //cout<<C[i];
        ans+=C[i]+48;
        }
        cout<<ans;
    //法二
    /*while(!C[len]&&len!=1)len--;//这里如果减到剩下一位就不要减了，得数0也有一位
    for(int i=len;i>0;i--)
        cout<<C[i];*/
}