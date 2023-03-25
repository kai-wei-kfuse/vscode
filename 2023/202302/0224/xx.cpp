#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1e5 + 5;

struct xx {
    int x, val;
    bool operator>(const xx& a) const { return val > a.val; }
};

priority_queue<xx, vector<xx>, greater<xx> > Q;  // 堆里存距离和点的编号
vector<xx> edge[N];
ll dist[N];
int vis[N];

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    int x, y, val;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> val;
        edge[x].push_back({y, val});
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = 0x7f3f3f3f;  // 到所有点的距离设为正无穷
    }
    dist[s] = 0;          // 自己到自己为0
    Q.push({s, 0});       // 先把自己放入队列
    while (!Q.empty()) {  // 优先队列
        int pos = Q.top().x;
        Q.pop();  // pop出来的都是已选顶点集合
        if (vis[pos]) continue;
        vis[pos] = 1;
        for (auto i : edge[pos]) {
            if (!vis[i.x] && dist[i.x] > dist[pos] + 1LL * i.val) {
                dist[i.x] = dist[pos] + 1LL * i.val;
                Q.push({i.x, (int)dist[i.x]});  // 编号和距离都要放进去
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
}