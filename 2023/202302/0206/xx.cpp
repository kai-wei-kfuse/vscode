#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct xx {
    int x, val;
    bool operator>(const xx& a) const { return val > a.val; }
};

priority_queue<xx, vector<xx>, greater<xx> > Q;  // 堆里存距离和点的编号
ll dist[100005];
int vis[100005];
vector<xx> edge[100005];

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    int x;
    xx tmp;
    for (int i = 1; i <= m; i++) {
        cin >> x >> tmp.x >> tmp.val;
        edge[x].push_back(tmp);
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = 2147483647;  // 到所有点的距离设为正无穷
    }
    dist[s] = 0;     // 自己到自己为0
    Q.push({s, 0});  // 先把自己放入队列
    while (!Q.empty()) {
        int pos = Q.top().x;
        Q.pop();
        if (vis[pos])
            continue;
        vis[pos] = 1;
        for (int i = 0; i < edge[pos].size(); i++) {
            int now = edge[pos][i].x;
            int val = edge[pos][i].val;
            if (!vis[now] && dist[now] > dist[pos] + 1LL * val) {
                dist[now] = dist[pos] + val;
                Q.push({now, (int)dist[now]});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
}