#include <algorithm>
#include <iostream>
using namespace std;

char a[1005], b[1005];
int dp[1005][1005];

int main() {
    int n, m;
    cin >> n >> m >> a + 1 >> b + 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if (a[i] == b[j])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    cout << dp[n][m];
}