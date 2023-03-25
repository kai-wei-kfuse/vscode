#include<iostream>
typedef long long ll;
using namespace std;
ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        ll n,s;
        n=read();
        s=read();
        if((n-1)*(n+1)>=s)printf("0\n");
        else {
            ll ans=s/(n*n);
            printf("%lld\n",ans);
        }
    }
}