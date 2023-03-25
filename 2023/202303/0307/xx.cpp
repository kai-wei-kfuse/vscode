#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> ve(n + 1), pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
        pref[i] += pref[i - 1] + ve[i];
    }
    vector<vector<int> > dp(n + 2, vector<int>(n + 2, 0));
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = 0x3f3f3f3f;
            for (int k = i; k <= j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + pref[j] - pref[i - 1]);
            }
        }
    }
    cout << dp[1][n];
}