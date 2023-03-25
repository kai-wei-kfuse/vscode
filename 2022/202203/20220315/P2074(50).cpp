#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
pair<int ,int >p;
queue< pair<int ,int > >Q;
int xx[]={-1,0,1,0};
int yy[]={0,1,0,-1};
int vis[610][610];
int main()
{
    int n,m,k,t;
    cin>>n>>m>>k>>t;
    int maxn=0;
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        memset(vis,0,sizeof(vis));
        Q.push(make_pair(x,y));
        vis[t][t]=1;
        int sum=0;
        while(!Q.empty()){
            for(int i=0;i<4;i++){
                int X=Q.front().first+xx[i];
                int Y=Q.front().second+yy[i];
                if(X<=n&&Y<=m&&X>=1&&Y>=1&&hypot(X-x,Y-y)<=t&&vis[X-x+t][Y-y+t]==0){
                    //cout<<X<<' '<<Y<<endl;
                    vis[X-x+t][Y-y+t]=1;
                    Q.push(make_pair(X,Y));
                }
            }
            Q.pop();
            sum++;
        }
        if(sum>maxn)maxn=sum;
    }
    cout<<maxn;
}