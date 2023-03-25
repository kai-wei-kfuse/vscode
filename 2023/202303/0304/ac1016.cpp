#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> ve(n + 1);
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
         dp[i] = ve[i];
    }
   // dp[1] = ve[1];
    int maxn = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (ve[j] < ve[i]) {
                dp[i] = max(dp[i], dp[j] + ve[i]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        maxn = max(dp[i], maxn);
    }
    cout << maxn;
}