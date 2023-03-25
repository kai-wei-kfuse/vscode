#include <bits/stdc++.h>
using namespace std;
vector<int> parent(2e5 + 2);
vector<int> edges[200005], edge[200005], edg[200005];
int find(int x) {
    while (parent[x] != x) {
        x = parent[x] = parent[parent[x]];
    }
    return x;
}
void root(int x, int y) {
    int x_rt = find(x);
    int y_rt = find(y);
    if (x_rt != y_rt)
        parent[x] = y_rt;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> ins(n + 1, 0), dist(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            edges[i].clear();
            edge[i].clear();
            edg[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            edges[y].push_back(x);
            edge[x].push_back(y);
        }
        // cout << 'x' << endl;
        for (int i = 1; i <= n; i++) {
            if (edges[i].empty())
                continue;
            int fa = edges[i][0];
            for (int j = 0; j < edges[i].size(); j++) {
                root(edges[i][j], fa);
            }
        }
        // cout << 'y' << endl;
        for (int i = 1; i <= n; i++) {
            for (auto x : edge[i]) {
                edg[find(i)].push_back(find(x));
                ins[find(x)]++;
            }
        }
        queue<int> q;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (find(i) == i) {
                cnt++;
                if (ins[i] == 0) {
                    q.push(i);
                }
            }
        }
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            cnt--;
            for (int i = 0; i < edg[p].size(); i++) {
                int u = edg[p][i];
                dist[u] = max(dist[u], dist[p] + 1);
                if (!--ins[u]) {
                    // dep[u] = dep[p] + 1;
                    q.push(u);
                }
            }
        }
        if (cnt)
            cout << "No";
        else {
            cout << "Yes" << endl;
            for (int i = 1; i <= n; i++) {
                int ans = dist[find(i)];
                // cout << ans << ' ';

                if (i != 1) {
                    ans -= dist[find(edges[i][0])];
                    // cout <<i<<' '<< find(edges[i][0])<<"|" << " ";
                }
                cout << ans << " ";
            }
        }
        cout << endl;
    }
}