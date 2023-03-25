#include<iostream>//结构体排序
#include<algorithm>
using namespace std;
struct bisai{
    int s,e;
}time[1000010];
bool rule(bisai a,bisai b)
{
    return a.e<b.e;
}
int main()
{
    int n,sum=0,f=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>time[i].s>>time[i].e;
    }
    sort(time+1,time+n+1,rule);
    for(int i=1;i<=n;i++)
    {
        if(time[i].s>=f)
        {
            sum++;
            f=time[i].e;
        }
    }
    cout<<sum;
    return 0;
}