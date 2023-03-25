#include <iostream>
const int mod = 1000007;
using namespace std;
int n, m;
int a[105];
int dp[105][105];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= min(j, a[i]); k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
            }
        }
    }
    cout << dp[n][m];
}