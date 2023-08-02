#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

signed main() {
    int t;
    cin >> t;
    vector<int> lcm(60);
    lcm[0] = 1;
    lcm[1] = 1;
    for (int i = 2; i <= 45; i++) {
        lcm[i] = lcm[i - 1] * i / __gcd(lcm[i - 1], i);
    }
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 2; lcm[i - 1] <= n; i++) {
            ans = (ans + i * (n / lcm[i - 1] - n / lcm[i]) % mod) % mod;
        }
        cout << ans << endl;
    }
}