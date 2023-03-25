#include<iostream>//组合数，费马小定理，快速幂,逆元
using namespace std;
const long long mod=1e9+7;
long long fact[1000005];
long long a,b,n,ans=0;
bool good(long long x){
    while(x){
        long long tmp=x%10;
        if(tmp!=a && tmp!=b)return false;
        x/=10;
    }
    return true;
}
long long fastpow(long long f,long long p){
    if(p==0)return 1;
    long long res=1;
    while(p){
        if(p&1)res=res*f%mod;
        f=f*f%mod;//反正每次模就行，不要让他超longlong
        p>>=1;
    }
    return res;
}
int main()
{
    cin>>a>>b>>n;
    fact[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i%mod;//打表，每次取模
    for(int i=0;i<=n;i++){
        if(good(a*i+b*(n-i))){
            long long tmp1=fastpow(fact[i],mod-2)%mod;//费马小定理求逆元
            long long tmp2=fastpow(fact[n-i],mod-2)%mod;//求完就取模
            ans += fact[n]*tmp1 %mod * tmp2 %mod;//因为n!已经取过模了，所以是后面两个取
            //fact[n]*tmp1 %mod * tmp2 %mod 就是组合数 
        }
    }
    printf("%lld\n",ans%mod);
}
