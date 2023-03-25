#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[(1 << 20) + 5];

signed main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int len = s.size();
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (((1 << j) & i) == 0) {
                dp[i | (1 << j)] = dp[i] + s[j];
            }
        }
    }
    sort(dp, dp + (1 << n));
    for (int i = 0; i < (1 << n); i++) {
        cout << dp[i] << ' ';
    }
}