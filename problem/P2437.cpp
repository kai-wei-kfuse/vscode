#include<iostream>//斐波那契（高精）
#include<algorithm>//蜜蜂路线
#include<cstring>
using namespace std;
#define maxn 2000
int a[maxn],b[maxn],tmp[maxn];
void pluss(int a[],int b[])
{
    memset(tmp,0,maxn);
    for(int i=1;i<=maxn;i++)
    {
        /*tmp[i]+=a[i]+b[i]+jw;
        jw=tmp[i]/10;
        tmp[i]%=10;*/
        tmp[i]+=a[i]+b[i];
        tmp[i+1]+=tmp[i]/10;
        tmp[i]%=10;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    a[1]=1;
    b[1]=1;
    if(m==1||m==2)cout<<"1";
    else
    {
    for(int i=3;i<=m-n+1;i++)
    {
        pluss(a,b);
        for(int j=1;j<=maxn;j++)
        {
            a[j]=b[j];
            b[j]=tmp[j];
        }
    }
    int flag=0;
    for(int i=maxn;i>0;i--)
    {
        if(tmp[i]!=0)flag=1;
        if(flag)
        cout<<tmp[i];
    }
    }
    return 0;
}