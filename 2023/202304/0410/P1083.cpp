#include <bits/stdc++.h>
using namespace std;

#define int long long

struct xx {
    int d, s, t;
};

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<xx> b(m + 2);
    for (int i = 1; i <= m; i++) {
        cin >> b[i].d >> b[i].s >> b[i].t;
    }
    auto chack = [&](int x) {
        vector<int> d(n + 2, 0);
        for (int i = 1; i <= n; i++) {
            d[i] = a[i] - a[i - 1];
        }
        for (int i = 1; i <= x; i++) {
            d[b[i].s] -= b[i].d;
            d[b[i].t + 1] += b[i].d;
        }
        for (int i = 1; i <= n; i++) {
            d[i] += d[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            if (d[i] < 0) return false;
        }
        return true;
    };
    int l = 0,
        r = m;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (chack(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    if (l == m) {
        cout << 0 << endl;
    } else {
        cout << "-1" << endl;
        cout << l + 1 << endl;
    }
}