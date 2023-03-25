#include<iostream>
using namespace std;
int a[100002],parent[100002],sign[100002];
int cmp1,cmp2;
int find(int x)
{
    while(x!=parent[x]){
        x=parent[x]=parent[parent[x]];
    }
    return x;
}
void root(int x,int y)
{
    int x_root=find(x);
    int y_root=find(y);
    if(x_root!=y_root)parent[x_root]=y_root;
}
int main()
{
    int ans=0;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        parent[i]=i;
        sign[a[i]]=i;
    }
    for(int i=1;i<=m;i++){
        cin>>cmp1>>cmp2;
        root(cmp1,cmp2);
    }
    for(int i=1;i<=n;i++){
        if(find(i)==find(sign[i]))ans++;
    }
    cout<<ans;
}