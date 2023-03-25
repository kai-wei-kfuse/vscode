#include<iostream>
using namespace std;
#define maxn 500005
int a[maxn],rmax[maxn][18],lg[maxn];
int n,m;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void init()
{
    for(int i=1;i<=n;i++){
        rmax[i][0]=a[i];
    }
    for(int j=1;(1 << j)<=n; j++){
        for(int i=1;i<=n-(1 << j)+1;i++){
            rmax[i][j]=max(rmax[i][j-1],rmax[i + (1 << j-1)][j-1]);
        }
    }
}
int query_max(int l,int r){
    int k=lg[r-l+1];
    return max(rmax[l][k],rmax[r-(1 << k) + 1][k]);
}
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=2;i<=n;i++){
        lg[i]=lg[i>>1]+1;
    }
    init();
    while(m--){
        int l,r;
        l=read();r=read();
        printf("%d\n",query_max(l,r));
    }
}