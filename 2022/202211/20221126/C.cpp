#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> mp;
        vector<int> ve(n);
        for (int i = 0; i < n; i++) {
            cin >> ve[i];
            mp[ve[i]]++;
        }
        sort(ve.begin(), ve.end());
        if (mp.size() == 1) {
            cout << n / 2 << endl;
            continue;
        }
        int ans = 0;
        for (auto i : mp) {
            int p = lower_bound(ve.begin(), ve.end(), i.first) - ve.begin();
            if (p != 0) {
                p--;
                // cout << i.first << ' ' << p << "gg" << endl;
                ans = max(ans, (n - p - 1) * (p + 1));
                // cout << (n - p - 1) << " " << (p + 1) << endl;
            }
            // cout << ans << endl;1 2 2 3 5 5
        }
        cout << ans << endl;
    }
}