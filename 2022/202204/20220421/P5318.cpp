#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> edge[1000005];
struct xx {
    int x, y;
} a[1000005];
int vis1[1000005], vis2[1000005];
int out[1000005];
bool cmp(xx a, xx b) {
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
void dfs(int x) {
    cout << x << ' ';
    for (int i = 0; i < edge[x].size(); i++) {
        if (vis1[edge[x][i]] == 0) {
            vis1[edge[x][i]] = 1;
            dfs(edge[x][i]);
        }
    }
    return;
}
int main() {
    int n, m;
    cin >> n >> m;
    int x, y;
    queue<int> Q;
    for (int i = 1; i <= m; i++) {
        cin >> a[i].x >> a[i].y;  // x->y
    }
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        // sort(edge[i].begin(), edge[i].end());
        edge[a[i].x].push_back(a[i].y);
    }
    vis1[1] = 1;
    dfs(1);
    cout << endl;
    vis2[1] = 1;
    Q.push(1);
    while (!Q.empty()) {
        int top = Q.front();
        Q.pop();
        cout << top << ' ';
        for (int i = 0; i < edge[top].size(); i++) {
            int now = edge[top][i];
            if (vis2[now] == 0) {
                Q.push(now);
                vis2[now] = 1;
            }
        }
    }
}