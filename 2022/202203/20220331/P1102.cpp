#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;
ll a[200005];
int main()
{
    int n,c;
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum+=upper_bound(a+1,a+n+1,a[i]-c)-lower_bound(a+1,a+n+1,a[i]-c);
        //cout<<sum<<endl;
    }
    cout<<sum;
}