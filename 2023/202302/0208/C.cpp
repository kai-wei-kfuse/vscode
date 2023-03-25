#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, a, b;
    string s;
    cin >> n >> a >> b;
    cin >> s;
    s = "?" + s + s;
    // cout << s << endl;
    int minn = b * (n / 2 + 1);
    for (int i = n; i <= 2 * n; i++) {
        int res = 0;
        res += (i - n) * a;
        int l, r;
        if (n % 2 == 0)
            l = i - n / 2, r = i - n / 2 + 1;
        else
            l = i - n / 2 - 1, r = i - n / 2 + 1;
        // cout << l << ' ' << r << endl;
        while (r - l + 1 <= n) {
            // cout << s[l] << ' ' << s[r] << endl;
            if (s[l] != s[r]) {
                res += b;
            }
            l--, r++;
        }
        //  cout << res << endl;
        minn = min(minn, res);
    }
    cout << minn;
}