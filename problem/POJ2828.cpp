#include<iostream>
#define maxx 200005
using namespace std;
int a[maxx],people[maxx],ans[maxx];
struct xx{
    int val,l,r;
}tree[4*maxx];
void build_tree(int node,int l,int r){
    tree[node].val=r-l+1;
    tree[node].l=l;
    tree[node].r=r;
    if(l==r)return;
    int mid=(l+r)>>1;
    build_tree(node<<1,l,mid);
    build_tree(node<<1|1,mid+1,r);
}
int query_tree(int node,int k){
    tree[node].val--;
    if(tree[node].l==tree[node].r)return tree[node].l;
    if(tree[node<<1].val<k)return query_tree(node<<1|1,k-tree[node<<1].val);
    else return query_tree(node<<1,k);
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a[i],&people[i]);
            a[i]++;
        }
        build_tree(1,1,n);
        for(int i=n;i>=1;i--)ans[query_tree(1,a[i])]=people[i];
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);
        printf("\n");
    }
}