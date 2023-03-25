#include<iostream>//均分纸牌
using namespace std;
int a[110];
int sum=0;
int main()
{
    int n;
    cin>>n;
    for(int i=1 ; i<=n ; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sum/=n;
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]!=sum)
        {
            a[i+1]-= sum - a[i];
            ans++;
        }
    }
    cout<<ans;
    return 0;
}