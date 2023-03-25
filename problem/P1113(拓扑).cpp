#include<iostream>//拓扑排序
#include<vector>
#include<queue>
using namespace std;
vector < int > edge[100005];//vactor存邻接表
int dp[100005],t[100005],ins[100005];
int main()
{
    int n,x,y;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>t[i];
        cin>>y;
        while(y){
            edge[y].push_back(x);//y->x的方向
            ins[x]++;//x入度加一
            cin>>y;
        }
    }
    queue <int >Q;
    for(int i=1;i<=n;i++){
        if(!ins[i]){
            Q.push(i);//第一步，遍历所有点，把入度为0的加入队列
            dp[i]=t[i];
        }
    }
    while(!Q.empty()){
        int p=Q.front();//第二步，取出点
        Q.pop();//取出来之后就不需要他了
        for(int i=0;i<edge[p].size();i++){
            int u=edge[p][i];//遍历p的下一个节点
            dp[u]=max(dp[u],dp[p]+t[u]);//我们需要时间最长的那个，所以是max
            ins[u]--;//第三步，入度减一
            if(!ins[u])Q.push(u);//如果入度为0，加入队列
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);//dp[n]不一定是最后才完成的任务，要找最大值
    }//有可能完成任务n的时候，因为前面的某个任务时间长，画样例的图，去掉几条边就能看出来了
    cout<<ans;
}