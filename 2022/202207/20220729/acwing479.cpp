#include <iostream>
using namespace std;

int a[35], dp[35][35], g[35][35];

void dfs(int l, int r) {
    if (r < l)
        return;
    int tmp = g[l][r];
    cout << tmp << ' ';
    dfs(l, tmp - 1), dfs(tmp + 1, r);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            if (len == 1)
                dp[i][j] = a[i], g[i][j] = i;
            else {
                for (int k = i; k <= j; k++) {
                    int right = k == j ? 1 : dp[k + 1][j];
                    int left = k == i ? 1 : dp[i][k - 1];
                    if (right * left + a[k] > dp[i][j]) {
                        dp[i][j] = right * left + a[k];
                        g[i][j] = k;
                    }
                }
            }
        }
    }
    cout << dp[1][n] << '\n';
    dfs(1, n);
}