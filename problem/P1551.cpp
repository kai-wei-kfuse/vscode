#include<iostream>//并查集模板
using namespace std;
int parent[5002];
int find(int x){
    while(parent[x]!=x){
        x=parent[x];
    }
    return x;    
    //if(x==parent[x])return x;
    //return parent[x]=find(parent[x]);
}
void root(int x,int y){
    int x_root=find(x);
    int y_root=find(y);
    if(x_root!=y_root)parent[x_root]=y_root;
    else return;
}
int main()
{
    int t,m,n;
    int x,y;
    cin>>t>>m>>n;
    for(int i=1;i<=t;i++){
        parent[i]=i;
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d",&x,&y);
        //cout<<'|'<<find(x)<<' '<<find(y);
        root(x,y);
        //cout<<'|'<<find(x)<<' '<<find(y)<<endl;
    }
    /*for(int i=1;i<=t;i++){
        cout<<i<<'|'<<parent[i]<<' ';
    }*/
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        if(find(x)==find(y))printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}