#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int len = s.length();
        s = " " + s;
        vector<int> sum(len + 1, 0);
        for (int i = 1; i <= len; i++) {
            sum[i] = sum[i - 1] + (s[i] == '1');
        }
        auto get = [&](int l, int r) {
            // cout << r - l - (sum[r] - sum[l - 1]) << endl;
            return max(sum[l] + sum[len] - sum[r - 1],
                       r - l - 1 + (sum[l] - sum[r - 1]));
        };
        int ans = len - sum[len];
        for (int l = 0, r = 1; l < len; l++) {
            r = max(l + 1, r);
            while (r + 1 <= len + 1 && get(l, r + 1) <= get(l, r))
                r++;
            ans = min(ans, get(l, r));
        }
        cout << ans << endl;
    }
}