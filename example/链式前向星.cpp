#include<iostream>//拓扑排序
#include<queue>
#include<vector>
using namespace std;
vector <int >edge[200005];
int ins[200005],outs[200005];
int sum[200005];
int main()
{
    int n,m,x,y;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        edge[x].push_back(y);
        ins[y]++;
        outs[x]++;
    }
    queue<int >Q;
    for(int i=1;i<=n;i++){
        if(ins[i]==0 && outs[i]){
            Q.push(i);
            sum[i]=1;
        }
    }
    while(!Q.empty()){
        int p=Q.front();
        Q.pop();
        for(int i=0;i<edge[p].size();i++){
            int u=edge[p][i];
            sum[u]+=sum[p];
            ins[u]--;
            if(!ins[u])Q.push(u);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!outs[i]){
            ans+=sum[i];
        }
    }
    cout<<ans;
}