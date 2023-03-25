#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s += '0';
        s = '0' + s;
        vector<int> ve(n + 1, 0), sum(n + 1, 0);
        vector<vector<int>> dp(n + 5, vector<int>(3));
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        if (ve[n] == '1')
            dp[n][1] = ve[n];
        for (int i = n - 1; i >= 1; i--) {
            dp[i][0] = max(dp[i + 1][0], max(dp[i + 1][1], dp[i + 1][2]));
            if (s[i] == '1') {
                dp[i][1] =
                    max({dp[i + 1][0], dp[i + 1][1], dp[i + 1][2]}) + ve[i];
            }
            if (s[i + 1] == '1' && s[i + 1] == '1') {
                dp[i][2] = max(dp[i + 1][0], dp[i + 1][2]) + ve[i];
            } else if (s[i + 1] == '1' && s[i + 2] == '0') {
                dp[i][2] = dp[i + 1][0] + ve[i];
            }
        }
        int ans = 0;
        ans = max(dp[1][0], max(dp[1][1], dp[1][2]));
        cout << ans << endl;
    }
}