#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        vector<int> ve(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            ans += ve[i] / k;
            ve[i] = ve[i] % k;
        }
        sort(ve.begin() + 1, ve.end(), greater<int>());
        int l = 1, r = n;
        while (l < r) {
            while (ve[l] + ve[r] < k && l < r) {
                r--;
            }
            if (r == l)
                break;
            ans++;
            l++;
            r--;
        }

        cout << ans << endl;
    }
}