#include<iostream>
using namespace std;
typedef long long ll;
const int mod=19260817;
inline ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f*=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=((x<<1)+(x<<3)+(ch^48))%mod;ch=getchar();}
    return x*f;
}
ll binpow(ll a,ll b){
    ll res=1;
    while(b>0){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int main()
{
    ll a,b;
    a=read();b=read();
    ll x=binpow(b,mod-2);
    printf("%lld",a*x%mod);
}