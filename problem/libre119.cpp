#include<iostream>//最短路
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
            mp[y][x]=w;//因为是无向图，所以正反都要连边
    }
    dist[st]=0;//自己到自己距离为0
    for(int i=1;i<=n;i++){
        int pos;
        int mins=maxn;
        for(int j=1;j<=n;j++){
            if(!visited[j] && dist[j]<mins){
                mins=dist[j];//找到距离最小的点
                pos=j;
            }
        }
        visited[pos]=1;//标记（pos是目前的出发点）
        for(int j=1;j<=n;j++){
            if(!visited[j] && dist[j]>dist[pos]+mp[pos][j]){
                dist[j]=dist[pos]+mp[pos][j];//
            }
        }
    }
    cout<<dist[en];
}