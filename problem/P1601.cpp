#include<bits/stdc++.h>//高精加.
using namespace std;
int A[520],B[520],C[520];
int main()
{
    string a,b;
    cin>>a>>b;
    int len=max(a.length(),b.length());//以最长的为结果长度
    for(int i=a.length()-1,j=1;i>=0;i--,j++)//反向输入，把个位放在数组的1位置（这里0位就不要了）
        A[j]=a[i]-'0';
    for(int i=b.length()-1,j=1;i>=0;i--,j++)
        B[j]=b[i]-'0';//-‘0’可以得到数字，用来把数字字符改成整形变量
    for(int i=1;i<=len;i++)
    {
        C[i]+=A[i]+B[i];//每个位直接加（可能会加超过10，下一步来处理）
        C[i+1]+=C[i]/10;//模拟进位（如果相加超过10，就会进位）
        C[i]=C[i]%10;//进位之后本位只剩个位
    }
    if(C[len+1])
    len++;//如果最高位进位，数长度要加一，为了输出
    for(int i=len;i>0;i--)
    cout<<C[i];
}