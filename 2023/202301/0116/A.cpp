#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int dp[100005][10];
int main() {
    int n;
    cin >> n;
    vector<int> ve(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
        ve[i] = (ve[i] - 1) % 9 + 1;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0];
        for (int j = 0; j <= 9; j++) {
            (dp[i][j] += dp[i - 1][j]) %= mod;
            (dp[i][((j + ve[i] - 1) % 9 + 1)] += dp[i - 1][j]) %= mod;
        }
    }
    for (int i = 1; i <= 9; i++) {
        cout << dp[n][i] << ' ';
    }
}