#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define inf 0x7fffffff
#define ll long long
#define int long long
//#define double long double
#define re register int
#define void inline void
#define eps 1e-8
//#define mod 1e9+7
#define ls(p) p<<1
#define rs(p) p<<1|1
#define pi acos(-1.0)
#define pb push_back
#define P pair < int , int >
#define mk make_pair
using namespace std;
const int mod=998244353;
const int M=1e9;
const int N=2e6+5;//?????????? 4e8
struct node
{
	int ver,next;
}e[N];
int tot,head[N];
int sz[N],son[N];
int col[N],cnt[N],ans[N];
int sum,flag,maxc;
int n;
void add(int x,int y)
{
	e[++tot].ver=y;
	e[tot].next=head[x];
	head[x]=tot;
}
void addedge(int x,int y)
{
	add(x,y);add(y,x);
}
void dfs1(int x,int pre)
{
	sz[x]=1;
	int ma=-1;
	for(re i=head[x];i;i=e[i].next)
	{
		int y=e[i].ver;
		if(y==pre)  continue;
		dfs1(y,x);
		sz[x]+=sz[y];
		if(ma<sz[y])  ma=sz[y],son[x]=y;
	}
}
void counts(int x,int pre,int val)
{
	cnt[col[x]]+=val;
	if(cnt[col[x]]>maxc)  maxc=cnt[col[x]],sum=col[x];
	else if(cnt[col[x]]==maxc)  sum+=col[x];
	for(re i=head[x];i;i=e[i].next)
	{
		int y=e[i].ver;
		if(y==pre||y==flag)  continue;
		counts(y,x,val);
	}
}
void dfs2(int x,int pre,bool keep)
{
	for(re i=head[x];i;i=e[i].next)
	{
		int y=e[i].ver;
		if(y==pre||y==son[x])  continue;
		dfs2(y,x,0);
	}
	if(son[x])
	{
		dfs2(son[x],x,1);
		flag=son[x];
	}
	counts(x,pre,1);
	flag=0;
	ans[x]=sum;
	if(!keep)
	{
		counts(x,pre,-1);
		sum=maxc=0;
	}
}
void solve()
{
	cin>>n;
	for(re i=1;i<=n;i++)  scanf("%lld",&col[i]);
	for(re i=1;i<n;i++)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		addedge(x,y);
	}
	dfs1(1,1);
	dfs2(1,1,0);
	for(re i=1;i<=n;i++)  printf("%lld ",ans[i]);
}
signed main()
{
    int T=1;
   cin>>T;
    for(int index=1;index<=T;index++)
    {
//        printf("Case #%lld: ",index);
        solve();
//        puts("");
    }
        for (int i = 1; i <= n;i++){
        cout << sz[i] << ' ';
    }
    cout << endl;
    for (int i = 1; i <= n;i++){
        cout << son[i] << ' ';
    }
    cout << endl;

    return 0;
}
/*


2
5
1
2
3
4
5
1 2
2 3
3 4
4 5
1
1 5 1

5
1
2
3
4
5
1 2
1 3
2 4
2 5
2
4 5 2
3 4 1

*/
