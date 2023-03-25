#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
const int lmax=1e6+10;
int lisprime[lmax];
int prime[lmax],a[lmax];
int cnt;

void sieve(){
    cnt=0;
    for(long long i=2;i<lmax;i++){//筛出1e6之前的所有质数
        if(!lisprime[i]){
            prime[++cnt]=i;
            for(long long j=2*i;j<lmax;j+=i){
                lisprime[j]=1;
            }
        }
    }
}
/*void sieve()//线性筛
{
	 cnt=0;
	for(int i=2;i<=lmax;i++)
	{
		if(lisprime[i]==0)
		{
			lisprime[i]=i;
			prime[++cnt]=i;		}
		for(int j=1;j<=cnt;j++)
		{
			if(prime[j]>lisprime[i]||prime[j]>lmax/i)break;
			lisprime[i*prime[j]]=prime[j];
		}
	}
}*/
signed main()
{
    int r,l;
    sieve();
    while(scanf("%lld %lld",&l,&r)!=EOF){
        memset(lisprime,0,sizeof(lisprime));
        if(l==1)lisprime[0]=1;
        for(int i=1;i<=cnt;i++){
            for(int j=l/prime[i];j*prime[i]<=r;j++){
                if(j>1 &&prime[i]*j-l>=0 ){lisprime[j*prime[i]-l]=1;
                //cout<<j*prime[i]-l<<' ';
                }
            }
        }
    int tmp=0;
    memset(a,0,sizeof(a));
    for(int i=l;i<=r;i++){
        if(!lisprime[i-l]){
            a[++tmp]=i;
            //cout<<a[tmp]<<' ';
        }
    }
    int ans1,ans2,ans3,ans4;
    int big=0,small=0x3f3f3f;
    if(tmp<=1){
        printf("There are no adjacent primes.\n");
        continue;
    }
    for(int i=2;i<=tmp;i++){
        if(a[i]-a[i-1]>big){
            big=a[i]-a[i-1];
            ans1=a[i-1];
            ans2=a[i];
        }
        if(a[i]-a[i-1]<small){
            small=a[i]-a[i-1];
            ans3=a[i-1];
            ans4=a[i];
        }
    }
        printf("%lld,%lld are closest, %lld,%lld are most distant.\n",ans3,ans4,ans1,ans2);
    }

}