#include<iostream>
using namespace std;
typedef long long ll;
ll p;
ll binpow(ll a,ll b){
    ll res=1;
    while(b>0){
        if(b&1)res=res*a%p;
        a=a*a%p;   
        b>>=1;
    }
    return res;
}
int main()
{
    ll n;
    scanf("%d %d",&n,&p);
    for(int i=1;i<=n;i++){
        printf("%lld\n",binpow(i,p-2)%p);
    }
}