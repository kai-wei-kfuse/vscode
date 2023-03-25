#include <cmath>
#include <iostream>
#include <map>
#include <vector>
typedef long long ll;
const ll mod = 1e9 + 7;

ll anss[] = {927105416, 745749140, 707741534, 882102328,
             781250051, 100000041, 31,        0};
ll res;
using namespace std;
void solve() {
    string a;
    cin >> a;
    int len = a.length();
    map<string, int> mp;
    string tmp = "";
    int num = 0;
    for (int i = 0; i < len; i += 2) {
        tmp = "";
        tmp += a[i];
        tmp += a[i + 1];
        // cout << tmp << ' ';
        mp[tmp]++;
    }
    for (auto i : mp) {
        if (i.second >= 2) {
            num++;
        }
    }
    cout << anss[num] << '\n';
}
long long qpow(long long a, long long b) {  //非递归
    // if(b==0)return 1;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;  // b&1:取第一位，如果是1说明需要，0说明不需要
        a = a * a % mod;
        b >>= 1;  //右移，1011 -> 101
    }
    return res;
}
int main() {
    /* for (int k = 0; k <= 7; k++) {
        vector<vector<ll> > dp(124, vector<ll>(8));
        dp[0][k] = 1;
        for (int i = 1; i <= 123; i++) {
            ll num = 123 - i + 1;
            ll ny = qpow(num, mod - 2);
            for (int j = k; j <= 7; j++) {
                ll yes = 3LL * (13LL - 2LL * (j - 1LL)) * ny % mod;
                ll no = (num - 3LL * (13LL - 2LL * j)) * ny % mod;
                if (j == 7)
                    dp[i][j] = dp[i - 1][j - 1] * yes % mod;
                else if (j == 0)
                    dp[i][j] = dp[i - 1][j] * no % mod;
                else
                    dp[i][j] =
                        (dp[i - 1][j] * no + dp[i - 1][j - 1] * yes) % mod;
                // cout << dp[i][j] << ' ';
            }
            // cout << endl;
        }
        ll ans = 0;
        for (ll i = 1; i <= 123; i++) {
            ans = (ans + dp[i][7] * i) % mod;
        }
        // cout << k << ':' << ans << ' ';
        // 0:927105416 1:745749140 2:707741534 3:882102328 4:781250051
        // 5:100000041 6:31 7:0
    } */
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Case #" << i << ':' << ' ';
        solve();
    }
}