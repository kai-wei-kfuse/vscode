#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

int main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > mp(n + 1);
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            dp[i] = dp[i - 1];
            for (auto j : mp[tmp]) {
                dp[i] = max(dp[i], dp[j - 1] + i - j + 1);
                if (dp[i] == i)
                    break;
            }
            mp[tmp].push_back(i);
        }
        cout << dp[n] << '\n';
    }
}