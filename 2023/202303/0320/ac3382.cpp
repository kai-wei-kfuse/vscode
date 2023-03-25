#include <bits/stdc++.h>
using namespace std;

#define int long long
int mod = 1e9;
vector<int> ve(40);
vector<int> dp(1000005, 0);
void init() {
    for (int i = 0; i <= 20; i++) {
        ve[i + 1] = (1 << i);
        //cout << ve[i + 1] << ' ';
    }
}
signed main() {
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= 21; i++) {
        for (int j = ve[i]; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - ve[i]]) % mod;
        }
    }
    cout << dp[n];
}