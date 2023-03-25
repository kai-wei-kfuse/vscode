#include <algorithm>
#include <iostream>
using namespace std;
int a[1005], val[1005], c[1005];
int dp[1005][1005];
int main() {
    int n, v, m;
    cin >> n >> v >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i] >> val[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= a[i]; j--) {
            for (int k = m; k >= c[i]; k--) {
                dp[j][k] = max(dp[j][k], dp[j - a[i]][k - c[i]] + val[i]);
            }
        }
    }
    cout << dp[v][m];
    return 0;
}
