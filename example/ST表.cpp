#include<iostream>
#include<algorithm>
#define maxn 500005
int n,q;
int a[maxn],lg[maxn],rmax[maxn][18],rmin[maxn][18];//2的19次方大于500000，所以取18
using namespace std;
/*
倍增：
1、输入原数组
2、预处理f数组，得到区间中的最值。预处理lg数组，得到log2N的最大整数
3、输入查询区间
4、求出区间长度，找到最大k，使得2^k小于区间长度L，左右两个区间合并得到最值
*/
void init(){
    for(int i=1;i<=n;i++){
        rmax[i][0]=rmin[i][0]=a[i];
    }
    for(int j=1;(1 << j)<=n;j++){
        for(int i=1;i <= n-(1 << j) + 1;i++ ){
            rmax[i][j]=max(rmax[i][j-1],rmax[i+(1 << j-1)][j-1]);
            rmin[i][j]=min(rmin[i][j-1],rmin[i+(1 << j-1)][j-1]);
        }
    }
}
int query_max(int l,int r)//区间最大值
{
    int k=lg[r-l+1];
    return max(rmax[l][k],rmax[r-(1 << k)+1][k]);
}
int query_min(int l,int r)//区间最小值
{
    int k=lg[r-l+1];
    return min(rmin[l][k],rmin[r-(1 << k)+1][k]);
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=2;i<=n;i++){
        lg[i]=lg[i >> 1]+1;
    }
    init();
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",query_max(l,r)-query_min(l,r));
    }
}