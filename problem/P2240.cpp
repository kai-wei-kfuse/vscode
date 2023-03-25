#include<iostream>//贪心
#include<cstdio>//部分背包
#include<algorithm>
using namespace std;
int n,t;
struct money{
    double m,p;
}coin[110];
bool rule(money a,money b)
{
    return a.p/a.m>b.p/b.m;
}
int main()
{
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>coin[i].m>>coin[i].p;
    }
    sort(coin+1,coin+n+1,rule);
    double sum=0,less=(double)t;//sum：装进去的总价值，less：背包剩下的空间
    /*for(int i=1;i<=n;i++)
    {
        cout<<coin[i].m<<" "<<coin[i].p<<endl;
    }*/
    for(int i=1;i<=n;i++)
    {
        if(coin[i].m>=less)
        {
            double result=sum+less*(coin[i].p/coin[i].m);
            printf("%.2f",result);
            return 0;
        }
        else
        {
            sum+=coin[i].p;
            less-=coin[i].m;
        }
    }
    printf("%.2f",sum);
}