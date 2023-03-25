#include<iostream>//并查集
using namespace std;
int parent[205];
int ans=0;
int find(int x){
    while(parent[x]!=x){
        x=parent[x]=parent[parent[x]];
    }
    return x;
}
void root(int r,int y){
    int r_root=find(r);
    int y_root=find(y);
    if(r_root!=y_root)parent[y_root]=r_root;//语言的根节点要设为人
}
int main()
{
    int rm,lm,l,k;
    int flag=0;
    scanf("%d %d",&rm,&lm);
    for(int i=1;i<=rm+lm;i++){
        parent[i]=i;
        }
    for(int i=1;i<=rm;i++){
        scanf("%d",&l);//语言种数
        if(l==0){
            ans++;
            parent[i]=-1;
            }
        else
        for(int j=1;j<=l;j++){
            scanf("%d",&k);
            root(i,k+rm);
            flag=1;
        }
    }
    for(int i=1;i<=rm;i++){
        if(parent[i]==i&&parent[i]!=-1)ans++;
    }
    if(!flag)ans++;
    cout<<ans-1;
}