#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 10;
int a[N];

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int maxn = -1e9;
        int minn = 1e9;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            maxn = max(maxn, a[i]);
            minn = min(minn, a[i]);
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= m; i++) {
            int aa, b, c;
            cin >> aa >> b >> c;
            if (c <= 0) {
                cout << "NO" << endl;
                continue;
            }
            int x = lower_bound(a + 1, a + n + 1, b) - a;
            int y = x - 1;
            // cout << a[x] << " " << a[y] << endl;
            if (x >= 1 && x <= n) {
                // cout << (b - a[x]) * (b - a[x]) - 4 * aa * c << endl;
                if ((b - a[x]) * (b - a[x]) < 4 * aa * c) {
                    cout << "Yes" << endl;
                    cout << a[x] << endl;
                    continue;
                }
            }
            if (y >= 1 && y <= n) {
                // cout << (b - a[y]) * (b - a[y]) - 4 * aa * c << endl;
                if ((b - a[y]) * (b - a[y]) < 4 * aa * c) {
                    cout << "Yes" << endl;
                    cout << a[y] << endl;
                    continue;
                }
            }
            cout << "NO" << endl;
            // } else if ((b - maxn) * (b - maxn) < 4 * a * c) {
            //     cout << "Yes" << endl;
            //     cout << maxn << endl;
            // } else if ((b - minn) * (b - minn) < 4 * a * c) {
            //     cout << "Yes" << endl;
            //     cout << minn << endl;
            // } else {
            //     cout << "NO" << endl;
            // }
        }
        cout << endl;
    }
}