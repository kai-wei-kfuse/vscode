#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;
int main()
{
    ll lmaxn=0;
    ll rmaxn;
    ll l,n;
    cin>>l>>n;
    rmaxn=l;
    ll tmp,x;
    while(n--){
        cin>>tmp>>x;
        if(x==0 && tmp>lmaxn)lmaxn=tmp;
        if(x==1 && tmp<rmaxn)rmaxn=tmp;
    }
    ll res=max(lmaxn,l-rmaxn);
    cout<<res;
}