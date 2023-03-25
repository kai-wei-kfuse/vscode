#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct xx {
    int x, val;
    bool operator>(const xx& a) const { return val > a.val; }
};
vector<xx> edge[100005];
priority_queue<xx, vector<xx>, greater<xx> > Q;
ll dist[100005];
int vis[100005];
int main() {
    int n, m, s;
    cin >> n >> m >> s;
    int x, y, val;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> val;
        edge[x].push_back({y, val});
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = 2147483647;
    }
    dist[s] = 0;
    Q.push({s, 0});
    while (!Q.empty()) {
        int pos = Q.top().x;
        Q.pop();
        if (vis[pos])
            continue;
        vis[pos] = 1;
        for (int i = 0; i < edge[pos].size(); i++) {
            int now = edge[pos][i].x;
            int val = edge[pos][i].val;
            if (!vis[now] && dist[now] > dist[pos] + val) {
                dist[now] = dist[pos] + val;
                Q.push({now, (int)dist[now]});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
}