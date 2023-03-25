#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=2e4+100; 
struct xx{
    int r,l;
}p[maxn];
int lsh[maxn<<1],lazy[maxn<<3];
int vis[maxn];
int ans=0;
void push_down(int node){
    if(lazy[node]){
        lazy[node<<1]=lazy[node];
        lazy[node<<1|1]=lazy[node];
        lazy[node]=0;
    }
}
void update_tree(int node,int l,int r,int ql,int qr,int k){
    if(ql<=l && qr>=r){
        lazy[node]=k;
        return;
    }
    push_down(node);
    int mid=(l+r)>>1;
    if(ql<=mid)update_tree(node<<1,l,mid,ql,qr,k);
    if(qr>mid)update_tree(node<<1|1,mid+1,r,ql,qr,k);
}
void query_tree(int node,int l,int r,int ql,int qr){
    if(ql<=l && qr>=r && lazy[node]!=0){
        if(!vis[lazy[node]]){
            //cout<<tree[node]<<'|';
            vis[lazy[node]]=1;
            ans++;
        }
        return;
    }
    if(l==r)return;
    //push_down(node);
    int mid=(l+r)>>1;
    if(ql<=mid)query_tree(node<<1,l,mid,ql,qr);
    if(qr>mid)query_tree(node<<1|1,mid+1,r,ql,qr);
}
int main()
{
    int c;
    scanf("%d",&c);
    while(c--){
        memset(vis,0,sizeof(vis));
        memset(lazy,0,sizeof(lazy));
        int n;
        scanf("%d",&n);
        int tot=1;//我们需要离散化的数的数量
        for(int i=1;i<=n;i++){
            scanf("%d %d",&p[i].l,&p[i].r);
            lsh[tot++]=p[i].l;
            lsh[tot++]=p[i].r;
        }
        sort(lsh+1,lsh+tot);
        tot=unique(lsh+1,lsh+tot)-lsh;
        //cout<<tot<<' ';
        int tmp=tot;
        for(int i=2;i<tmp;i++){
            if(lsh[i]-lsh[i-1]>1)lsh[tot++]=lsh[i-1]+1;
        }
        sort(lsh+1,lsh+tot);
        /*for(int i=1;i<tot;i++)cout<<lsh[i]<<' ';
        cout<<endl;*/
        for(int i=1;i<=n;i++){
            int l,r;
            l=lower_bound(lsh+1,lsh+tot,p[i].l)-lsh;
            r=lower_bound(lsh+1,lsh+tot,p[i].r)-lsh;
            //cout<<l<<' '<<r;
            update_tree(1,1,tot-1,l,r,i);
            /*for(int i=1;i<=4*n;i++){
                cout<<lazy[i]<<" ";
            }
            cout<<endl;*/
        }
        ans=0;
        query_tree(1,1,tot-1,1,tot-1);
        cout<<ans<<endl;
    }
}