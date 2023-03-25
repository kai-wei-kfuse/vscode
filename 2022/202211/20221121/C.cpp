#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1), ve2(n + 1), ans(n + 1);
        int maxn = 0, maxnn = -0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            ve2[i] = ve[i];
            maxn = max(maxn, ve[i]);
        }
        sort(ve2.begin() + 1, ve2.end());
        for (int i = 1; i <= n; i++) {
            if (ve[i] != maxn) {
                ans[i] = ve[i] - maxn;
            } else {
                ans[i] = ve[i] - ve2[n - 1];
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
}