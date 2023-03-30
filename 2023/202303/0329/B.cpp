#include <bits/stdc++.h>
using namespace std;

#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > ve(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> ve[j][i];
            }
        }
        for (int i = 1; i <= m; i++) {
            sort(ve[i].begin() + 1, ve[i].end());
        }
        // for (int i = 1; i <= m; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         cout << ve[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        int ans = 0;
        vector<int> v(m + 1, 0);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                v[j] += (ve[j][i] - ve[j][i - 1]) * (i - 1);
            }
            for (int j = 1; j <= m; j++) {
                // cout << v[j] << ' ';
                ans += v[j];
            }
            // cout << endl;
        }
        cout << ans << endl;
    }
}