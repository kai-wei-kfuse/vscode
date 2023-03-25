#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1), pref(n + 1, 0);
        map<int, int> mp;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            pref[i] = pref[i - 1] + ve[i];
        }
        for (int i = 1; i <= n; i++) {
            if (ve[i] == 0)
                break;
            else if (pref[i] == 0)
                ans++;
        }
        int maxn = 0;
        for (int i = n; i >= 1; i--) {
            mp[pref[i]]++;
            maxn = max(mp[pref[i]], maxn);
            if (ve[i] == 0) {
                ans += max(1LL, maxn);
                maxn = 0;
                mp.clear();
            }
        }
        cout << ans << endl;
    }
}