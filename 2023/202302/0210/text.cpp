#include <bits/stdc++.h>
using namespace std;

struct xx {
    int x, val;
    bool operator>(const xx& a) const { return val > a.val; }
};

const int N = 1e5 + 5;
priority_queue<xx, vector<xx>, greater<xx>> Q;
int dist[N], vis[N];
vector<xx> edge[N];

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edge[x].push_back({y, z});
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = 0x3f3f3f3f;
    }
    dist[s] = 0;
    Q.push({s, 0});
    while (!Q.empty()) {
        int pos = Q.top().x;
        Q.pop();
        if (vis[pos])
            continue;
        vis[pos] = 1;
        for (auto i : edge[pos]) {
            if (!vis[i.x] && dist[i.x] > dist[pos] + i.val) {
                dist[i.x] = dist[pos] + i.val;
                Q.push({i.x, dist[i.x]});
            }
        }
    }
    cout << dist[t];
}