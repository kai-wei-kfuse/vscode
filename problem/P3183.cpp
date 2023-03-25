#include<iostream>
#include<queue>
using namespace std;
int n,m,eat[100002],ate[100002],ans=0,t[100002];
struct Edge{
    int to,next;
}edge[1000002];
int head[100002],cnt=1;
void add_edge(int u,int v){//链式前向星
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;//cnt：边的编号
}
int main()
{
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=m;i++){
        cin>>x>>y;//x是被吃，y是吃
        add_edge(x,y);
        eat[y]++;
        ate[x]++;//eat指他吃几种动物，ate指他被几种动物吃
    }
    queue<int >Q;
    for(int i=1;i<=n;i++){
        if(!eat[i] && ate[i]){
            Q.push(i);
            t[i]=1;
        }
    }
    while(!Q.empty()){
        int p=Q.front();
        Q.pop();
        for(int i=head[p];i;i=edge[i].next){
            int v=edge[i].to;
            t[v]+=t[p];
            eat[v]--;
            if(eat[v]==0)Q.push(v);
        }
    }
    for(int i=1;i<=n;i++){
        if(!ate[i]){//如果是食物链顶端，那么为0
            ans+=t[i];
        }
    }
    cout<<ans;
}