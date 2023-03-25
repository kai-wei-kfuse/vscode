#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;
vector<ll> edge[5005];
vector<vector<ll> > dp(5005, vector<ll>(5005));

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    // for (int j = 1; j <= n; j++)
    dp[0][1] = 1;

    for (int i = 1; i <= k; i++) {
        ll a1 = 0;
        for (int j = 1; j <= n; j++) {
            a1 = (a1 + dp[i - 1][j]) % mod;
        }
        for (int j = 1; j <= n; j++) {
            ll a2 = 0;
            for (auto x : edge[j]) {
                a2 = (a2 + dp[i - 1][x]) % mod;
            }
            dp[i][j] = (a1 - a2 - dp[i - 1][j] + mod) % mod;
            //cout << dp[i][j] << ' ';
        }
        //cout << endl;
    }
    cout << dp[k][1];
}
