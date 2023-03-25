#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    vector<int> ve(100005), pref(100005, 0);
    while (t--) {
        int n, m;
        cin >> n >> m;
        int mm = m;
        int idx = 0;
        int maxn = 0, ans = 0;
        int flag = 1;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            pref[i] = pref[i - 1] + ve[i];
            if (pref[i] > m && flag) {
                if (maxn < ve[i]) {
                    ans = i;
                    maxn = ve[i];
                }
                flag = 0;
            } else if (flag) {
                if (maxn < ve[i]) {
                    ans = i;
                    maxn = ve[i];
                }
            }
        }
        if (pref[n]<=mm) {
            cout << "0" << endl;
        } else
            cout << ans << endl;
    }
}