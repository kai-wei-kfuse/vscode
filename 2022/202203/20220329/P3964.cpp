#include<iostream>
#include<algorithm>
#include <climits>
#include <stdio.h>
typedef long long ll;
const ll maxn=1e6 + 5;
using namespace std;
ll x[maxn],y[maxn],hx[maxn],hy[maxn];
ll sumx[maxn],sumy[maxn];
/*
距离最小：
1、输入
1.5、排序，求前缀和
2、切比雪夫转化为哈曼顿坐标系
3、计算到所有点的哈曼顿距离
4、找最小
*/
int n;
ll solve(int i){
    ll xi=lower_bound(hx+1,hx+1+n,x[i]) -hx;
    ll yi=lower_bound(hy+1,hy+n+1,y[i]) -hy;
    return xi*1LL*x[i]-sumx[xi]+sumx[n]-sumx[xi]-(n-xi)*1LL*x[i]+yi*1LL*y[i]-sumy[yi]+sumy[n]-sumy[yi]-(n-yi)*1LL*y[i];
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>n;
    int xx,yy;
    for(int i=1;i<=n;i++){
        cin>>xx>>yy;
        x[i]=hx[i]=xx+yy;
        y[i]=hy[i]=xx-yy;
    }
    sort(hx+1,hx+n+1);
    sort(hy+1,hy+n+1);
    for(int i=1;i<=n;i++){
        sumx[i]=sumx[i-1]+hx[i];
        sumy[i]=sumy[i-1]+hy[i];
    }
    ll ans=LLONG_MAX;
    for(int i=1;i<=n;i++){
        ans=min(ans,solve(i));
    }
    //cout<<(ans>>1LL)<<endl;
    printf("%lld", ans >> 1LL);
}