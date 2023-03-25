#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int parent[100002];
struct city{
    int x,y,id;//id代表第id座城市，无论用x坐标还是y坐标排序最终结果都是用城市来排序
}a[100002];
struct node{
    int a,b;
    int val;
}edge[200005];
bool cmpx(city a,city b){
    return a.x<b.x;
}
bool cmpy(city a,city b){
    return a.y<b.y;
}
bool cmpv(node a,node b){
    return a.val<b.val;
}
int find(int x)
{
    while(parent[x]!=x){
        x=parent[x]=parent[parent[x]];
    }
    return x;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i].x,&a[i].y);
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmpx);
    for(int i=1;i<n;i++){//注意循环到第n-1座城市就停止，因为会有i+1，连上最后一座城市
        edge[i].a=a[i].id;
        edge[i].b=a[i+1].id;//我们需要每相邻的两座城市都建边。
        edge[i].val=abs(a[i+1].x-a[i].x);//求每条边的权值
    }
    sort(a+1,a+1+n,cmpy);
    for(int i=1;i<n;i++){
        edge[i+n-1].a=a[i].id;
        edge[i+n-1].b=a[i+1].id;
        edge[i+n-1].val=abs(a[i+1].y-a[i].y);
    }//这时我们得到一个新数组edge，存的是每两座城市之间的边
    //接下来我们开始正常的求最小生成树
    sort(edge+1,edge+1+(n-1)*2,cmpv);//边数比城市数少一，所以是（n-1）*2
    memset(parent,0,sizeof(parent));
    int ans=0,cnt=0;
    for(int i=1;i<=n;i++)parent[i]=i;
    for(int i=1;i<=(n-1)*2;i++){
        int x_root=find(edge[i].a);
        int y_root=find(edge[i].b);
        if(x_root==y_root)continue;
        else
        {
            parent[x_root]=y_root;
            ans+=edge[i].val;
            cnt++;
        }
        //if(cnt==n)break;
    }
    cout<<ans;
}