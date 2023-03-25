#include <bits/stdc++.h>
using namespace std;

const int N = 25000 * 100;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int maxn = 0;
        vector<int> ve(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        sort(ve.begin() + 1, ve.end());
        maxn = ve[n];
        vector<int> dp(maxn + 5);
        dp[0] = 1;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dp[i] == 1) {
                continue;
            }
            ans++;
            for (int j = ve[i]; j <= maxn; j++) {
                dp[j] |= dp[j - ve[i]];
            }
        }
        cout << ans << endl;
    }
}