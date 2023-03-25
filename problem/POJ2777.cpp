#include<iostream>
#include<cstring>
using namespace std;
struct tmp{
    int val,l,r,lazy;
}tree[404000];
int vis[35];
int ans;

void build_tree(int node,int l,int r){
    tree[node].lazy=0;
    tree[node].val=1;
    tree[node].l=l;
    tree[node].r=r;
    if(l==r)return;
    int left_node=node<<1;
    int right_node=node<<1|1;
    int mid=(r+l)>>1;
    build_tree(left_node,l,mid);
    build_tree(right_node,mid+1,r);
    //tree[node].val=tree[left_node].val+tree[right_node].val;
}
/*
void build_tree(int color,int n){
    for(int i = 1;i <= 4*n;i++){
        tree[i].val = 1;
    }
}*/
void push_down(int node,int l,int r){
    if(tree[node].lazy){
    tree[node<<1].lazy=tree[node].lazy;
    tree[node<<1|1].lazy=tree[node].lazy;
    tree[node<<1].val=tree[node].lazy;
    tree[node<<1|1].val=tree[node].lazy;
    tree[node].lazy=0;
    }
}
void update_tree(int node,int L,int R,int k){ 
    if(L<=tree[node].l && R>=tree[node].r){
        tree[node].val=k;
        tree[node].lazy=k;
        return;
    }
    int left_node=node<<1;
    int right_node=node<<1|1;
    int mid=(tree[node].r+tree[node].l)>>1;
    push_down(node,tree[node].l,tree[node].r);
    if(L<=mid)update_tree(left_node,L,R,k);
    if(mid<R)update_tree(right_node,L,R,k);
    if(tree[left_node].val==tree[right_node].val)
        tree[node].val=tree[left_node].val;
    else
        tree[node].val=-1;
}
void query_tree(int node,int a,int b){
    if(a<=tree[node].l && b>=tree[node].r){
        //cout<<'['<<tree[node].val<<']';
        if(tree[node].val==0)return;
        if(tree[node].val==-1){
            push_down(node,tree[node].l,tree[node].r);
            int left_node=node<<1;
            int right_node=node<<1|1;
            int mid=(tree[node].r+tree[node].l)>>1;
            //cout<<mid<<"<- "<<a<<' ';
            if(a<=mid)query_tree(left_node,a,b);
            if(mid<b)  query_tree(right_node,a,b);    
        }
        else{
            if(!vis[tree[node].val]){
            vis[tree[node].val]=1;
            //cout<<'|'<<tree[node].val<<' ';
            ans++;
            }
        }
        return;
    }
    push_down(node,tree[node].l,tree[node].r);
    int left_node=node<<1;
    int right_node=node<<1|1;
    int mid=(tree[node].r+tree[node].l)>>1;
    if(a<=mid)query_tree(left_node,a,b);
    if(mid<b)  query_tree(right_node,a,b);
}
int main()
{
    int n,t,m;
    while(scanf("%d %d %d",&n,&t,&m)!=EOF){
        
    build_tree(1,1,n);
    while(m--){
        char a;
        //cin>>a;
        getchar();
        scanf("%c",&a);
        if(a=='C'){
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            if(y<x){
                int tmp=x;
                x=y;
                y=tmp;
            }
            update_tree(1,x,y,z);
            /*for(int i=1;i<=4*n;i++){
                cout<<tree[i].val<<' ';
            }
            cout<<endl;*/
        }
        else{
            memset(vis,0,sizeof(vis));
            int x,y;
            ans=0;
            scanf("%d %d",&x,&y);
             if(y<x){
                int tmp=x;
                x=y;
                y=tmp;
            }
            query_tree(1,x,y);
            /*for(int i=1;i<=t;i++){
                if(vis[i])ans++;
            }*/
            printf("%d\n",ans);
        }
    }
    }
}