#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll niyuan(int x) {
    return qpow(x, mod - 2);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> ve(n + 1);
    ve[0] = 1;
    for (int i = 1; i <= n; i++) {
        ll tmp;
        cin >> tmp;
        ve[i] = tmp * ve[i - 1] % mod;
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << ve[r] * niyuan(ve[l - 1]) % mod << '\n';
    }
}