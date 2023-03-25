#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int maxn = 0, l = 0x3f3f3f3f, r = 0, res = 0, costlen = 0x3f3f3f3f;
        int ln = 0, rn = 0;
        int lastl = 0x3f3f3f3f, lastr = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            int l_, r_, co;
            cin >> l_ >> r_ >> co;
            if (l_ < l) {
                l = l_;
                lastl = co;
            }
            if (l_ == l) {
                lastl = min(lastl, co);
            }
            if (r_ > r) {
                r = r_;
                lastr = co;
            }
            if (r_ == r) {
                lastr = min(lastr, co);
            }
            if (maxn < r_ - l_ + 1) {
                maxn = r_ - l_ + 1;
                costlen = co;
            } else if (maxn == r_ - l_ + 1) {
                costlen = min(costlen, co);
            }

            res = lastl + lastr;
            if (maxn == r - l + 1) {
                res = min(costlen, res);
            }
            cout << res << endl;
        }
    }
}