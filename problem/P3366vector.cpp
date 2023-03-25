#include<iostream>
#include<algorithm>
using namespace std;
struct xx{
    int a,b,val;
}edge[200005];
int parent[5005];
bool cmp(xx a,xx b){
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
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&edge[i].a,&edge[i].b,&edge[i].val);
    }
    for(int i=1;i<=n;i++)parent[i]=i;
    sort(edge+1,edge+1+m,cmp);
    int ans=0,cnt=0;
    for(int i=1;i<=m;i++){
        int x_root=find(edge[i].a);
        int y_root=find(edge[i].b);
        if(x_root==y_root)continue;
        else{
            parent[x_root]=y_root;
            ans+=edge[i].val;
            cnt++;
        }
        if(cnt==n-1){
            printf("%d",ans);
        return 0;}
    }
    printf("orz");
}