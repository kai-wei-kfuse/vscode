#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int dest[100005];
vector<int> edge[100005];
void dfs(int x, int p) {
    dest[x] = p;
    for (int i = 0; i < edge[x].size(); i++) {
        int now = edge[x][i];
        if (dest[now] == 0)
            dfs(now, p);
    }
    return;
}
int main() {
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        edge[y].push_back(x);
    }  // x->y
    for (int i = n; i >= 1; i--) {
        if (dest[i] == 0) {
            dfs(i, i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dest[i] << ' ';
    }
}