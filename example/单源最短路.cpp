#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=0x3f3f3f;
int mp[2502][2502];
int visited[2502],dist[2502];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int st,en;
    scanf("%d %d",&st,&en);
    int x,y,w;
    memset(mp,maxn,sizeof(mp));
    memset(dist,maxn,sizeof(dist));
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&x,&y,&w);
            mp[x][y]=w;
            mp[y][x]=w;
    }
    dist[st]=0;
    for(int i=1;i<=n;i++){
        int pos;
        int mins=maxn;
        for(int j=1;j<=n;j++){
            if(!visited[j] && dist[j]<mins){
                mins=dist[j];
                pos=j;
            }
        }
        visited[pos]=1;
        for(int j=1;j<=n;j++){
            if(!visited[j] && dist[j]>dist[pos]+mp[pos][j]){
                dist[j]=dist[pos]+mp[pos][j];
            }
        }
    }
    cout<<dist[en];
}
