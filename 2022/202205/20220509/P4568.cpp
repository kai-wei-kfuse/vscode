#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct xx {
    ll x, val;
    bool operator>(const xx& a) const { return val > a.val; }
};
vector<xx> edge[300005];
priority_queue<xx, vector<xx>, greater<xx> > Q;
ll dist[300005];
int vis[300005];
int main() {
    int n, m, k;
    int s, t, x, y, val;
    cin >> n >> m >> k;
    cin >> s >> t;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> val;
        edge[x].push_back({y, val});
        edge[y].push_back({x, val});
        for (int j = 1; j <= k; j++) {
            edge[x + j * n - n].push_back({y + j * n, 0});
            edge[x + j * n].push_back({y + j * n, val});
            edge[y + j * n - n].push_back({x + j * n, 0});
            edge[y + j * n].push_back({x + j * n, val});
        }
    }
    memset(dist, 90, sizeof(dist));
    dist[s] = 0;
    Q.push({s, 0});
    while (!Q.empty()) {
        int pos = Q.top().x;
        Q.pop();
        if (vis[pos])
            continue;
        for (int i = 0; i < edge[pos].size(); i++) {
            ll now = edge[pos][i].x;
            ll val = edge[pos][i].val;
            if (!vis[now] && dist[now] > dist[pos] + val) {
                dist[now] = dist[pos] + val;
                Q.push({now, (int)dist[now]});
            }
        }
    }
    // cout << dist[t];
    ll ans = 0x3f3f3f;
    for (int i = 0; i <= k; i++) {
        ans = min(dist[t + i * n], ans);
    }
    cout << ans;
}
/*
5 6 1
0 4
0 1 5
1 2 5
2 3 5
3 4 5
2 3 3
0 2 100
*/