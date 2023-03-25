#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c, d;
        cin >> n >> c >> d;
        vector<int> ve(n + 1, 0), pref(n + 1, 0);
        int maxn = 0;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            maxn = max(ve[i], maxn);
        }
        if (maxn * d < c) {
            cout << "Impossible" << endl;
            continue;
        }
        sort(ve.begin() + 1, ve.end(), greater<int>());
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + ve[i];
        }
        if (pref[min(d, n)] >= c) {
            cout << "Infinity" << endl;
            continue;
        }
        auto chack = [&](int t) {
            int cnt = 0;
            int x = t + 1;
            if (x <= n) {
                cnt = (d / x) * pref[x] + pref[d % x];
            } else {
                cnt = (d / x) * pref[n];
                if (d % x <= n) {
                    cnt += pref[d % x];
                } else {
                    cnt += pref[n];
                }
            }
            // cout << t << " " << cnt << endl;
            if (cnt >= c)
                return 1;
            else
                return 0;
        };
        // cout << "k" << endl;
        int l = 0, r = d;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (chack(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << r << endl;
    }
}