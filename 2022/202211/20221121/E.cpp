#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1);
        int f0 = 0, f1 = 0;
        int n0 = 0, n1 = 0;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            if (f0 == 0 && ve[i] == 0) {
                f0 = i;
            }
            if (ve[i] == 1) {
                f1 = i;
            }
        }

        int ans = 0;
        for (int i = n; i >= 1; i--) {
            if (ve[i]) {
                n1++;
            } else {
                n0++;
            }
            if (ve[i] == 1) {
                ans += n0;
            }
        }
        int tmp = 0, tp = 0;
        if (f1) {
            tmp = n1 - 1ll - (n - f1);
        }
        if (f0) {
            tp = n0 - 1ll - (f0 - 1ll);
        }
        cout << ans + max({tmp, tp, 0LL}) << endl;
    }
}