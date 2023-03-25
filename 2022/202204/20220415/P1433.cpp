#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;
struct xx {
    double x, y;
} a[20];
int vis[20];
double dist[20][20];
double ans = 1000000002;
int n, cnt = 0;
double dis(int x, int y) {
    return sqrt((a[x].x - a[y].x) * (a[x].x - a[y].x) +
                (a[x].y - a[y].y) * (a[x].y - a[y].y));
}
void dfs(int p, int now, double sum) {
    cnt++;
    if (cnt >= 10000000) {
        printf("%.2lf", ans);
        exit(0);
    }
    if (sum >= ans)
        return;
    if (p == n) {
        ans = min(sum, ans);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            double tmp = sum + dist[now][i];
            if (tmp >= ans)
                continue;
            vis[i] = 1;
            dfs(p + 1, i, tmp);
            vis[i] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dist[i][j] = dis(i, j);
            // cout << dist[i][j] << "    ";
        }
        // cout << endl;
    }
    dfs(0, 0, 0);
    printf("%.2lf", ans);
}