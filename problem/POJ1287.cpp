#include<iostream>
#include<algorithm>
using namespace std;
struct Edge{
    int x,y,val;
}edge[2502];
int parent[52];
bool cmp(Edge a,Edge b)
{
    return a.val<b.val;
}
int find(int x){
    while(parent[x]!=x){
        x=parent[x]=parent[parent[x]];
    }
    return x;
}
int main()
{
    int n,m;
    scanf("%d",&n);
    while(n!=0){
        int ans=0,cnt=0;
        scanf("%d",&m);
        if(n==1)printf("0\n");
        for(int i=1;i<=m;i++){
            scanf("%d %d %d",&edge[i].x,&edge[i].y,&edge[i].val);
        }
        for(int i=1;i<=n;i++)parent[i]=i;
        sort(edge+1,edge+m+1,cmp);
        for(int i=1;i<=m;i++){
        int x_root=find(edge[i].x);
        int y_root=find(edge[i].y);
        if(x_root==y_root)continue;
        else
        {
            parent[x_root]=y_root;
            ans+=edge[i].val;
            //cout<<edge[i].x<<' '<<edge[i].y<<' '<<edge[i].val<<'|';
            cnt++;//点数
        }
        if(cnt==n-1){
            printf("%d\n",ans);
            }
        }
        scanf("%d",&n);
    }
}