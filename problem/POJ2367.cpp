#include<iostream>
#include<queue>
using namespace std;
/*
int n,cnt=1;
struct Edge{
    int to,next;
}edge[1000002];
int head[1000002],in[1000002];
void add_edge(int u,int v){//链式前向星
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;//cnt：边的编号
    in[v]++;
}
int main()
{
    cin>>n;
    int v;
    for (int i = 0; i <= n; i++) head[i] = -1;
    for(int i=1;i<=n;i++){
        cin>>v;
        while(v){
            add_edge(i,v);
            cin>>v;
        }
    }
    queue < int > Q;
    for(int i=1;i<=n;i++){
        if(in[i]==0)Q.push(i);
    }
    while(!Q.empty()){
        int p=Q.front();
        Q.pop();
        cout<<p<<" ";
        for(int i=head[p];i!=-1;i=edge[i].next){
            in[i]--;
            if(in[i]==0)Q.push(i);
        }
    }
}*/
int v;
int in[110],res[110],mp[110][110],cnt=0;
queue< int >Q;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        while(scanf("%d",&v),v){
            mp[i][v]=1;
            in[v]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(in[i]==0)Q.push(i);
    }
    while(!Q.empty()){
        int p=Q.front();
        res[++cnt]=p;
        //cout<<p<<'|';
        Q.pop();
        for(int i=1;i<=n;i++){
            if(mp[p][i]){
            if((--in[i])==0)
                Q.push(i);
            }
        }
    }
    for(int i=1; i<n; i++)
        printf("%d ",res[i]);
        printf("%d\n",res[n]);
}