#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> edge[n + 1], vis(n + 1);
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        for (auto j : edge[i]) {
            if (j > i) {
                vis[i]++;
            }
        }
        if (vis[i] == 0)
            ans++;
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            int u, v;
            cin >> u >> v;
            if (u > v) {
                if (vis[v] == 0)
                    ans--;
                vis[v]++;
            } else {
                if (vis[u] == 0)
                    ans--;
                vis[u]++;
            }
        } else if (x == 2) {
            int u, v;
            cin >> u >> v;
            if (u > v) {
                vis[v]--;
                if (vis[v] == 0)
                    ans++;
            } else {
                vis[u]--;
                if (vis[u] == 0)
                    ans++;
            }
        } else {
            cout << ans << endl;
        }
    }
}