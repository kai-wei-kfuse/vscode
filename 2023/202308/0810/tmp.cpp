#include <bits/stdc++.h>
using namespace std;

struct xx {
    int x, val, fl;
};

const int N = 1e6 + 5;

vector<xx> edg[N];
vector<array<int, 2>> dist(N, {0x3f3f3f3f, 0x3f3f3f3f}), vis(N, {0, 0});

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, s, k;
        cin >> n >> m >> s >> k;
        set<int> se;
        for (int i = 1; i <= m; i++) {
            int x, y, val, fl;
            cin >> x >> y >> val >> fl;
            edg[x].push_back({y, val, fl});
        }
        for (int i = 1; i <= n; i++) {
            if (i != s)
                se.insert(i);
        }
        dist[s][0] = 0;
        priority_queue<xx> q;
        q.push({s, 0, 0});
        while (!q.empty()) {
            xx pos = q.top();
            q.pop();
            if (vis[pos.x][pos.fl]) continue;
            vis[pos.x][pos.fl] = 1;
        }
    }
}