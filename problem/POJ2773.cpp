#include<iostream>
#include<cstring>
using namespace std;
int gcd(int n,int m)
{
    if(m==0)
        return n;
    return gcd(m,n%m);
}
int a[1000010];
int main()
{
    int m,k;
    while(~scanf("%d%d",&m,&k))
    {
        memset(a,0,sizeof(a));
        int tot=0;
        for(int i=1;i<=m;i++)
        {
            if(gcd(i,m)==1)
                a[++tot]=i;
        }
        a[0]=a[tot];
        printf("%d\n",(k-1)/tot*m+a[k%tot]);
    }
}
