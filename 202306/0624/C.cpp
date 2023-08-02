#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, pair<int, int> > mp1;
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            if (i >= 2) {
                dp[i] = dp[i - 1];
                if (mp1[tmp].second != 0) {
                    int x = mp1[tmp].first - (n - i);
                    dp[i] = max(dp[i], x + 1);
                }
            }
            if (dp[i - 1] + n - i > mp1[tmp].first || mp1[tmp].first == 0) {
                mp1[tmp].first = dp[i - 1] + n - i;
                mp1[tmp].second = i;
            }
        }
        cout << dp[n] << endl;
    }
}