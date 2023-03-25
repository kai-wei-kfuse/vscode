#include<iostream>//数楼梯
#include<cstdio>
#include<cstring>
#define Max 2000
using namespace std;
int a[Max],b[Max],tmp[Max];
void pluss(int a[],int b[])
{
    memset(tmp,0,sizeof(tmp));
    for(int i=1;i<=Max;i++)
    {
        tmp[i]+=a[i]+b[i];
        tmp[i+1]+=tmp[i]/10;
        tmp[i]%=10;
    }
}
int main()
{
    int n;
    cin>>n;
    a[1]=1;
    b[1]=2;
    if(n==1)cout<<"1";
    else if(n==2)cout<<"2";
    else 
    {
        for(int i=3;i<=n;i++)
    {
        pluss(a,b);
        for(int j=1;j<=Max;j++)
        {
            a[j]=b[j];
            b[j]=tmp[j];
            }
    }
    int flag=0;
    for(int i=Max;i>0;i--)
    {
        if(b[i]!=0)flag=1;
        if(flag)cout<<tmp[i];
    }
    return 0;
    }
}