#include<iostream>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll a[105][105],n,p;
ll ans[105][105];
ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
inline void mul1(){
    ll c[105][105]={0};
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            for(int j=1;j<=n;j++){
                c[i][j]=(c[i][j]+a[i][k]*ans[k][j])%mod;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans[i][j]=c[i][j];
        }
    }
}
inline void mul2(){
    ll c[105][105]={0};
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            for(int j=1;j<=n;j++){
                c[i][j]=(c[i][j]+a[i][k]*a[k][j])%mod;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=c[i][j];
        }
    }
}
int main()
{   
    n=read();p=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=read();
        }
    }
    for(register int i=1;i<=n;i++)
        ans[i][i]=1;
    while(p){
        if(p&1)
        mul1();
        mul2();
        p>>=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%lld ",ans[i][j]%mod);
        }
        printf("\n");
    }
}