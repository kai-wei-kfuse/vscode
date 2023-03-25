#include<iostream>
#include<set>
typedef long long ll;
using namespace std;
#define maxn 10000005
ll prime[10000000];
ll lisprime[10000005];
int visit[maxn];
int vis[maxn];
set<int >se;
void Prime(){
    for (int i = 2;i <= maxn; i++) {
        //cout<<" i = "<<i<<endl;
        if (!visit[i]) {
            prime[++prime[0]] = i;      //纪录素数， 这个prime[0] 相当于 cnt，用来计数
        }
        for (int j = 1; j <=prime[0] && i*prime[j] <= maxn; j++) {
//            cout<<"  j = "<<j<<" prime["<<j<<"]"<<" = "<<prime[j]<<" i*prime[j] = "<<i*prime[j]<<endl;
            visit[i*prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}
void sieve()//线性筛
{
	int cnt=0;
	for(int i=2;i<=10000000;i++)
	{
		if(lisprime[i]==0)
		{
			lisprime[i]=i;
			prime[++cnt]=i;		}
		for(int j=1;j<=cnt;j++)
		{
			if(prime[j]>lisprime[i]||prime[j]>10000000/i)break;
			lisprime[i*prime[j]]=prime[j];
		}
	}
}
ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
int main()
{
    int n;
    cin>>n;
    ll x,y;
    ll res;
    Prime();
    while(n--){
        int ans=0;
        x=read();y=read();
        //res=x;
        //ll x=res;
        //int flag=0;
        se.clear();
        for(ll i=1;prime[i]<=x/prime[i];i++){
            while(x%prime[i]==0){x/=prime[i];
           // cout<<prime[i]<<endl;
            se.insert(prime[i]);
        }}
        for(ll i=1;prime[i]<=y/prime[i];i++){
            while(y%prime[i]==0){y/=prime[i];
            se.insert(prime[i]);
            //cout<<prime[i]<<endl;
        }}
        //cout<<x<<endl;
        //cout<<y<<endl;
        if(x>1)se.insert(x);
        if(y>1)se.insert(y);
        cout<<se.size()<<endl;
    }
}