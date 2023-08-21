#include <bits/stdc++.h>
using namespace std;

#define int long long 

struct xx {
    int x, val;
    bool operator<(const xx& a) const {
        return val > a.val;
    }
};

vector<xx> edge[105];
vector<int> lev(105, 0);

signed main() {
    int k, n;
    cin >> k >> n;
    for (int i = 1; i <= n; i++) {
        int val, level, m;
        cin >> val >> level >> m;
        lev[i] = level;
        edge[n + 1].push_back({i, val});
        for (int j = 1; j <= m; j++) {
            int v, val;
            cin >> v >> val;
            edge[v].push_back({i, val});
        }
    }

    int ans = 1e12;
    priority_queue<xx> q;
    

    
    for (int i = lev[1] - k; i <= lev[1]; i++) {
        lev[n + 1] = i;
        int mx = i + k, mi = i;
        q.push({n + 1, 0});
        
        vector<int> vis(n + 2, 0);
        vector<int> dist(n + 2, 1e12);
        dist[n + 1] = 0;
        while (!q.empty()) {
            int pos = q.top().x;
            q.pop();
            if (vis[pos])
                continue;
            vis[pos] = 1;
            for (auto [x, val] : edge[pos]) {
                if (lev[x] >= mi && lev[x] <= mx) {
                    if (!vis[x] && dist[x] > dist[pos] + val) {
                        dist[x] = dist[pos] + val;
                        q.push({x, dist[x]});
                    }
                }
            }
        }

        ans = min(ans, dist[1]);
    }
    cout << ans << endl;
}