#include<iostream>//排队接水
#include<algorithm>
using namespace std;
struct aaa{
    int t,i;
}a[1010];
bool rule(aaa a,aaa b)
{
    return a.t<b.t;
}
int main()
{
    double n;
    cin>>n;
    double sum=0,num=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].t;
        a[i].i=i;
    }
    sort(a+1,a+(int)n+1,rule);
    for(int i=1;i<=n;i++)
        {
        num+=a[i-1].t;
        sum+=num;  
        cout<<a[i].i<<" ";
        }
    cout<<endl;
    printf("%.2f",sum/n);
    return 0;
}