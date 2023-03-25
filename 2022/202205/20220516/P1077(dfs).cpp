#include <iostream>
using namespace std;
int a[105], me[105][105];
const int mod = 1000007;
int m, n;
int dfs(int x, int p) {
    if (p == m)
        return 1;
    if (p > m)
        return 0;
    if (x > n)
        return 0;
    if (me[x][p])
        return me[x][p];
    int ans = 0;
    for (int i = 0; i <= a[x]; i++) {
        ans = (ans + dfs(x + 1, p + i)) % mod;
    }
    return me[x][p] = ans;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << dfs(1, 0);
    // cout << endl;
    // for (int i = 0; i <= 30; i++) {
    //     for (int j = 0; j <= 30; j++) {
    //         cout << me[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
}