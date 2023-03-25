洛谷P3183
<img src="https://img-blog.csdnimg.cn/6773910c86704758ab59aaac7f286b73.png" width="60%" height="30%" >
如图所示为某生态系统的食物网示意图，据图回答第1小题现在给你n个物种和m条能量流动关系，求其中的食物链条数。物种的名称为从1到n编号M条能量流动关系形如a1 b1a2 b2a3 b3......am-1 bm-1am bm其中ai bi表示能量从物种ai流向物种bi,注意单独的一种孤立生物不算一条食物链

**输入格式**
第一行两个整数n和m,接下来m行每行两个整数ai bi描述m条能量流动关系。（数据保证输入数据符号生物学特点，且不会有重复的能量流动关系出现）1<=N<=100000 0<=m<=200000题目保证答案不会爆 int

**输出格式**
一个整数即食物网中的食物链条数

**输入输出样例**
**输入 #1**
10 16
1 2
1 4
1 10
2 3
2 5
4 3
4 5
4 8
6 5
7 6
7 9
8 5
9 8
10 6
10 7
10 9
**输出 #1**
9
典型的DAG。
题目要求食物链条数，我们需要知道，从最头的部分（不吃任何动物）到最尾的动物（没有动物吃他），这样才算一条食物链（生产者是头，消费者是尾）。那么我们就不止要存入度也要存出度了。

```cpp
#include<iostream>//拓扑排序
#include<queue>
#include<vector>
using namespace std;
vector <int >edge[200005];
int ins[200005],outs[200005];
int sum[200005];
int main()
{
    int n,m,x,y;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        edge[x].push_back(y);
        ins[y]++;
        outs[x]++;
    }
    queue<int >Q;
    for(int i=1;i<=n;i++){
        if(ins[i]==0 && outs[i]){
            Q.push(i);
            sum[i]=1;
        }
    }
    while(!Q.empty()){
        int p=Q.front();
        Q.pop();
        for(int i=0;i<edge[p].size();i++){
            int u=edge[p][i];
            sum[u]+=sum[p];
            ins[u]--;
            if(!ins[u])Q.push(u);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!outs[i]){
            ans+=sum[i];
        }
    }
    cout<<ans;
}
```