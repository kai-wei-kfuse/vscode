#include<iostream>//最小生成树
#include<algorithm>
using namespace std;
int a,b;
struct node{
    int x,y,val;//存两点一边
}edge[200005];
int parent[5005];
bool cmp(node a,node b)//自定义排序规则
{
    return a.val<b.val;
}
int find(int x){
    while(parent[x]!=x){
        x=parent[x]=parent[parent[x]];//路径压缩
    }
    return x;
}
void root(int x,int y){
    int x_root=find(x);
    int y_root=find(y);
    if(x_root!=y_root)parent[x_root]=y_root;//合并操作
}
int main()
{
    int n,m,ans=0,cnt=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){//输入
        scanf("%d %d %d",&edge[i].x,&edge[i].y,&edge[i].val);
    }
    for(int i=1;i<=n;i++)parent[i]=i;//初始化
    sort(edge+1,edge+m+1,cmp);//排序
    for(int i=1;i<=m;i++){
        int x_root=find(edge[i].x);
        int y_root=find(edge[i].y);
        if(x_root==y_root)continue;//根节点相同，说明已经在一个集合了
        else
        {
            //root(edge[i].x,edge[i].y);
            parent[x_root]=y_root;//合并
            ans+=edge[i].val;//ans：权值
            cnt++;//cnt:点数
        }
        if(cnt==n-1){
            printf("%d",ans);
            return 0;
        }
    }
    printf("orz");
}
