#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
map <int,int> mp;
ll a[200005];
int main()
{
    int n,c;
    cin>>n>>c;
    int tmp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum+=mp[a[i]-c];
    }
    cout<<sum;
}