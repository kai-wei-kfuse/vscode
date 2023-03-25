#include<iostream>
#include<queue>
using namespace std;
int t,n,m,x,y;
int xx[]={2,2,1,-1,-2,-2,-1,1};
int yy[]={-1,1,2,2,1,-1,-2,-2};
struct xy{
    int x,y;
};
bool vis[11][11];
int sum=0;
int main()
{
    cin>>t;
    cin>>n>>m>>x>>y;
    queue < xy > Q;
    Q.push((xy){x,y});
    vis[x][y]=1;
    while(!Q.empty()){
        for(int i=0;i<8;i++){
            int X=Q.front().x+xx[i];
            int Y=Q.front().y+yy[i];
            if(X>=0 && Y>=0 && X<n && Y<m && vis[X][Y]==0){
                vis[X][Y]=1;
                Q.push((xy){X,Y});
                int flag = 0;
                for(int j=0;j<n;j++){
                    for(int k=0;k<m;k++){
                        cout<<vis[j][k]<<' ';
                        if(vis[j][k]==0)flag=1;
                    }
                    cout<<endl;
                }
                if(flag==0)sum++;
            }
        }
        Q.pop();
    }
    cout<<sum;
}