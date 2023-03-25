#include<iostream>//并查集
#define m 998244353
using namespace std;
int parent[4000002];
int find(int a)
{
    while(parent[a]!=a){
        a=parent[a]=parent[parent[a]];
    }
    return a;
}
void root(int a,int b){
    int a_root=find(a);
    int b_root=find(b);
    if(a_root!=b_root)parent[a_root]=b_root;
}
int main()
{
    int n,t;
    int x,a,b;
    scanf("%d %d",&n,&t);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    int ans=0;
    for(int i=1;i<=t;i++){
        scanf("%d %d %d",&x,&a,&b);
        if(x==1){
            if(find(a)==find(b)){
                ans*=2;
                ans++;
                ans%=m;
            }
            else{
                ans*=2;
                ans%=m;
            }
        }
        else{
            root(a,b);
        }
    }
    cout<<ans;
}