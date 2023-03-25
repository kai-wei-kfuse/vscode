#include <algorithm>
#include <iostream>
using namespace std;

int a[205][205], dp[205][205];

int main() {
    int x, y;
    cin >> x >> y;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            cin >> a[i][j];
            dp[i][j] = -0x3f3f3f;
        }
    }
    for (int i = 0; i <= x; i++) {
        dp[i][0] = -0x3f3f3f;
        dp[i][y + 1] = -0x3f3f3f;
    }
    dp[x][y / 2 + 1] = a[x][y / 2 + 1];
    dp[x][y / 2 + 2] = a[x][y / 2 + 2];
    dp[x][y / 2] = a[x][y / 2];
    // for (int i = y / 2 + 3; i <= y; i++) {
    //     dp[x][i] = dp[x][i - 1] + a[x][i];
    // }
    // for (int i = y / 2; i >= 1; i--) {
    //     dp[x][i] = dp[x][i + 1] + a[x][i];
    // }
    for (int i = x - 1; i >= 1; i--) {
        for (int j = 1; j <= y; j++) {
            dp[i][j] = max(
                dp[i + 1][j] + a[i][j],
                max(dp[i + 1][j - 1] + a[i][j], dp[i + 1][j + 1] + a[i][j]));
            // cout << dp[i][j] << ' ';
        }
        // cout << endl;
    }
    int ans = -0x3f3f3f;
    for (int i = 1; i <= x; i++) {
        ans = max(ans, dp[1][i]);
    }
    cout << ans;
}