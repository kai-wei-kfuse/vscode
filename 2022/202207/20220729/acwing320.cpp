#include <algorithm>
#include <iostream>
using namespace std;

int a[210], dp[210][210];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int len = 3; len <= n + 1; len++) {
        for (int i = 1; i + len - 1 <= 2 * n; i++) {
            int j = i + len - 1;
            for (int k = i + 1; k < j; k++) {
                dp[i][j] =
                    max(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[k] * a[j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i][i + n]);
    }
    cout << ans;
}