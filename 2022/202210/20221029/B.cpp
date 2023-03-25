#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> len(n + 1);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            ans += x * 2 + y * 2;
            len[i] = max(x, y);
        }
        // cout << ans << endl;
        sort(len.begin() + 1, len.end(), greater<int>());
        for (int i = 2; i <= n; i++) {
            ans -= len[i] * 2;
            // cout << len[i] << ' ';
        }
        cout << ans << endl;
    }
}