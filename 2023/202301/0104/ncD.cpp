#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

void S(int n, vector<int>& a, int cnt = 1) {
    while (cnt--)
        for (int i = 1; i <= n; i++) {
            a[i] = a[i] + a[i - 1];
            a[i] %= mod;
        }
}

void D(int n, vector<int>& a, int cnt = 1) {
    while (cnt--) {
        for (int i = n; i >= 1; i--) {
            a[i] = ((a[i] - a[i - 1]) % mod + mod) % mod;
        }
    }
}

int f(int x, vector<int> a, int k) {
    int ret = 0;
    int base = 1;
    for (int i = k; i >= 0; i--) {
        ret += base * a[i] % mod;
        ret %= mod;
        base = base * x % mod;
    }
    return ret;
}

int g(int x, vector<int> a, int k, int l, int r) {
    return (mod - f(x + r - l + 1, a, k)) % mod;
}

signed main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n + 20, 0);
    vector<int> b(20), f1(20), f2(20);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    D(n, a, 6);
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        int k;
        cin >> k;
        for (int j = 0; j <= k; j++) {
            cin >> b[j];
        }
        for (int i = 1; i <= 10; i++) {
            f1[i] = f(i, b, k);
            f2[i] = g(i, b, k, l, r);
        }
        D(10, f1, 6);
        D(10, f2, 6);
        for (int i = 1; i <= 10; i++) {
            a[l + i - 1] += f1[i];
            a[l + i - 1] %= mod;
            a[r + i] += f2[i];
            a[r + i] %= mod;
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    S(n, a, 7);
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        cout << ((a[r] - a[l - 1]) % mod + mod) % mod << endl;
    }
}
