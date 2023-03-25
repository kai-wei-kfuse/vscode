#include<iostream>
#include<algorithm>
using namespace std;
struct tr{
    int l,r;
}tree[1000005];
int sum=0;
int dfs(int i){
    if(i==0)return 0;
    return max(dfs(tree[i].l),dfs(tree[i].r))+1;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&tree[i].l,&tree[i].r);
    }
    cout<<dfs(1);
}