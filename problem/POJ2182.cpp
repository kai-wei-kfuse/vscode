#include<iostream>
using namespace std;
int a[8005],ans[8005];
struct xx{
    int v,l,r;//可以不用结构体，用的原因是在查找的时候就不用再函数参数加l和r了
}tree[400005];//线段树数组要是原数组4倍
void build_tree(int node,int l,int r)
{
    tree[node].v=r-l+1;//初始时[l, r]区间中的数的个数为 r - l + 1
    tree[node].l=l;
    tree[node].r=r;
    if(l==r)return;
    int left_node=node<<1;//2*node
    int right_node=node<<1|1;//2*node+1
    int mid=(l+r)>>1;//(l+r)/2
    build_tree(left_node,l,mid);
    build_tree(right_node,mid+1,r);
}
int query_tree(int node,int k){//因为用结构体，所以不用传入l和r
    tree[node].v--;
    //for(int i=1;i<=10;i++)cout<<tree[i].v<<' ';
    //cout<<endl;
    //如果搜到了叶子结点（左节点等于右节点），那么必定是这个值了
    if(tree[node].l==tree[node].r)return tree[node].l;
    int left_node=node<<1;//2*node
    int right_node=node<<1|1;//2*node+1
    //cout<<tree[left_node].v<<'|'<<k<<endl;
    //左子区间的值的个数不足x个，那么就在右子区间找第 x - k大的数（k为左区间数的个数）
    if(tree[left_node].v<k)return query_tree(right_node,k-tree[left_node].v);
	//左区间的数的个数 >= x，那么就在左区间搜索即可
    else return query_tree(left_node,k);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        scanf("%d",&a[i]);//因为只有n-1个数据，第一头牛没有数据
    }
    a[1]=0;//好像没用，反正第一头牛没数据，0就对了
    build_tree(1,1,n);
    //for(int i=1;i<=10;i++)cout<<tree[i].v<<' ';
    for(int i=n;i>=1;i--)ans[i]=query_tree(1,a[i]+1);//存的时候就倒着存
    for(int i=1;i<=n;i++)printf("%d\n",ans[i]);//输出的时候就正着输
}
