#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 25, M = 1 << 20;
int val[N][N], dp[M][N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> val[i][j];
        }
    }
    memset(dp, 0x3f, sizeof dp);
    dp[1][1] = 0;  // dp[0][1]=0
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >> (j - 1) & 1)
                for (int k = 1; k <= n; k++) {
                    dp[i][j] =
                        min(dp[i][j], dp[i - (1 << (j - 1))][k] + val[k][j]);
                }
        }
    }
    cout << dp[(1 << n) - 1][n];
}