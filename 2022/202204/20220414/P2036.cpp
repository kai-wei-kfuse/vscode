#include <algorithm>
#include <iostream>
using namespace std;
struct xx {
    int x, y;
} a[11];
int vis[11];
int n;
int ans = 0x3f3f3f;
void dfs(int x) {
    int res = 0, res2 = 1;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 1) {
            res2 *= a[i].x;
            res += a[i].y;
        }
    }
    if (res != 0)
        ans = min(abs(res - res2), ans);

    for (int i = x; i <= n; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            dfs(i);
            vis[i] = 0;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    dfs(1);
    cout << ans;
}