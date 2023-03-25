#include<iostream>
#include<vector>
#include<algorithm>
#define maxn 500005
using namespace std;
int n,m,s;
int dist[maxn],anc[maxn][20];
vector<int > tr[maxn];
/*
倍增算法求LCA：
1、存树（按存图方法）
2、求每个节点的深度
3、求每个节点的2^k级祖先
4、输入
5、把两个节点提高到同一深度（倍增法）
6、把两个节点一起提升直到节点相同为止（同样倍增法）
*/
void dfs(int now,int last){
    for(int i=0;i<tr[now].size();i++){
        int next=tr[now][i];
        if(next==last)continue;
        dist[next]=dist[now]+1;
        anc[next][0]=now;
        dfs(next,now);
    }
}
void init(){
    for(int j=1;j<=18;j++){
        for(int i=1;i<=n;i++){
            anc[i][j]=anc[anc[i][j-1]][j-1];
        }
    }
}
int lca(int u,int v){
    if(dist[u]<dist[v])swap(u,v);
    for(int i=18;i>=0;i--){
        if(dist[anc[u][i]]>=dist[v])u=anc[u][i];
    }
    if(u==v)return u;
    for(int i=18;i>=0;i--){
        if(anc[u][i]!=anc[v][i]){
            u=anc[u][i];
            v=anc[v][i];
        }
    }
    return anc[u][0];
}

void addedge(int x,int y){
    tr[x].push_back(y);
    tr[y].push_back(x);
}
int main()
{
    scanf("%d%d%d",&n,&m,&s);
    int x,y;
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        addedge(x,y);
    }
    dist[s]=1;
    dfs(s,0);
    init();
    //cout<<'d';
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        printf("%d\n",lca(u,v));
    }
}