#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> edge[200005], vis(200005);
pair<int, int> p[200005];

void dfs(int x) {
    cout << x << ' ';
    if (!edge[x].empty())
        for (int i : edge[x]) {
            // int y = edge[x][i];
            if (vis[i] == 0) {
                // cout << vis[i] << endl;
                vis[i] = x;
                // cout << i << '|' << endl;
                dfs(i);
                cout << x << ' ';
            }
        }
    // cout << vis[x] << ' ';
}

int main() {
    int n;
    cin >> n;
    int x, y;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        // cout << p[i].first << ' ' << p[i].second << '\n';
        sort(edge[i].begin(), edge[i].end());
    }
    vis[1] = 1;
    dfs(1);
}