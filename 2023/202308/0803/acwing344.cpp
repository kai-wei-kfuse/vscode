#include<bits/stdc++.h>
using namespace std;

#define int long long

int edg[105][105];
int valu[105][105];
int mid[105][105];
vector<int >path;
void getpath(int i,int j){//搜索i到j的路径
    if(mid[i][j]==0){
        return;
    }
    int k=mid[i][j];
    getpath(i,k);//处理左边
    path.push_back(k);//把中间的点加进去
    getpath(k,j);//处理右边
}

signed main(){
    int n,m;
    cin>>n>>m;
    memset(edg,30,sizeof(edg));
    memset(valu,30,sizeof(valu));
    for(int i=1;i<=n;i++){
        edg[i][i]=0;
        valu[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        int x,y,val;
        cin>>x>>y>>val;
        edg[x][y]=min(val,edg[x][y]);
        edg[y][x]=edg[x][y];
        valu[x][y]=edg[x][y];
        valu[y][x]=edg[y][x];
    }
    int ans=0x3f3f3f3f;
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<k;i++){
            for(int j=i+1;j<k;j++){
                if(edg[i][j]+valu[j][k]+valu[k][i]<ans){
                    ans=edg[i][j]+valu[j][k]+valu[k][i];
                    path.clear();
                    path.push_back(k);
                    path.push_back(i);
                    getpath(i,j);
                    path.push_back(j);
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(edg[i][j]>edg[i][k]+edg[k][j]){
                    edg[i][j]=edg[i][k]+edg[k][j];
                    mid[i][j]=k;
                }
            }
        }
    }
    if(ans==0x3f3f3f3f){
        cout<<"No solution."<<endl;
    }
    else{
        for(auto i:path){
            cout<<i<<" ";
        }
    }
}