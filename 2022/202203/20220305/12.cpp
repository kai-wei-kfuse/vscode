#include<iostream>
#include<cstring>
using namespace std;
int parent[10005];
int vis[10005];
int viss[10005];
int sum=0,sums=0;
int find(int x){
    while(parent[x]!=x){
        x=parent[x]=parent[parent[x]];
    }
    return x;
}
void root(int x,int y){
    int x_root=find(x);
    int y_root=find(y);
    if(x_root!=y_root)parent[x_root]=y_root;
}

int main()
{
    int n,x,y;
    cin>>n;
    for(int i=1;i<=10004;i++){
        parent[i]=i;
    }
    while(n--){
        int k;
        cin>>k;
        cin>>x;
        if(!vis[x]){vis[x]=1;sum++;}
        for(int i=1;i<k;i++){
            cin>>y;
            if(!vis[y]){vis[y]=1;sum++;}
            root(x,y);
        }
    }
    for(int i=1;i<=sum;i++){
        if(parent[i]==i)sums++;
    }
    cout<<sum<<' '<<sums<<endl;
    int t;
    cin>>t;
    while(t--){
        cin>>x>>y;
        if(find(x)==find(y))cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
}
