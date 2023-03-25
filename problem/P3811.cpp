#include<iostream>
using namespace std;
typedef long long ll;
ll inv[3000005]={0,1};
int main()
{
    int n,p;
    scanf("%d%d",&n,&p);
    printf("1\n");
    for(int i=2;i<=n;i++){
        inv[i]=(ll)p-(p/i)*inv[p%i]%p,printf("%lld\n",inv[i]);
    }
    return 0;
}