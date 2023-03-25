#include<iostream>
#include<cstring>
using namespace std;
const int maxn=0x3f3f3f;
int mp[2005][2005];
int dist[2005],vis[2005];
int main()
{
    int t,n,x,y,v;
    cin>>t>>n;
    memset(mp,maxn,sizeof(mp));
    memset(dist,maxn,sizeof(dist));
    for(int i=1;i<=t;i++){
        cin>>x>>y>>v;
        if(v<mp[x][y]){
        mp[x][y]=v;
        mp[y][x]=v;
        }
    }
    dist[n]=0;
    for(int i=1;i<=n;i++){
        int pos;
        int mins=maxn;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&dist[j]<mins){
                mins=dist[j];
                pos=j;
            }
        }
        vis[pos]=1;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&dist[j]>dist[pos]+mp[pos][j]){
                dist[j]=dist[pos]+mp[pos][j];
                }
        }
    }
    cout<<dist[1];
}