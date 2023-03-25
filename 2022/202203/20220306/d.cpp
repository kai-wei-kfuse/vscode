#include<iostream>
#include<cstring>
typedef long long ll;
using namespace std;
ll x[10200];
ll binpow(ll a,ll b,ll p,ll c){
    ll res=c;
    while(b){
        if(b&1)res=(res*a)%p;
            a=(a*a)%p;
            b>>=1;
    }
    return res%p;
}
int main()
{
    ll a,b,c;
    //scanf("%d%d%d",&a,&b,&c);
    cin>>a>>b>>c;
    int cnt=1;
    while(a!=0&&b!=0&&c!=0){//s=c乘b的a次方
        int time;
        memset(x,0,sizeof(x));
        scanf("%d",&time);
        for(int i=1;i<=time;i++){
            scanf("%lld",&x[i]);
            }
        printf("Case %d:\n",cnt++);
        for(int i=1;i<=time;i++){
            //printf("%lld",binpow(b,a,x[i],c));
            cout<<binpow(b,a,x[i],c);
            if(i<time)cout<<' ';
        }
        //printf("\n");
        cout<<endl;
        //scanf("%d%d%d",&a,&b,&c);
        cin>>a>>b>>c;
    }
}