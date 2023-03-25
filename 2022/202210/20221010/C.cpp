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
        int tot = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            if (++tot > ve[i]) {
                ans += (tot) / 2.0 * (tot - 1);
                ans -= (1 + ve[i] - 1) / 2.0 * (ve[i] - 1);
                tot = ve[i];
            }
        }
        ans += (1 + tot) / 2.0 * tot;
        cout << ans << endl;
    }
}