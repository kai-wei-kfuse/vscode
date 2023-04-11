#include <bits/stdc++.h>
using namespace std;

vector<int> ve[3000005];
int main() {
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        ve[y].push_back(x - 1);
        mx = max(mx, y);
    }
    vector<int> dp(mx + 2, 0);
    for (int i = 1; i <= mx; i++) {
        dp[i] = dp[i - 1];
        for (auto it : ve[i]) {
            dp[i] = max(dp[i], dp[it] + i - it);
        }
    }
    cout << dp[mx] << endl;
}