#include <bits/stdc++.h>
using namespace std;
#define ac return
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, a1, b1, a2, b2;
        cin >> x >> y >> a1 >> b1 >> a2 >> b2;
        int flag = 0;
        int mx, my;
        int tmp1 = x - a1;
        int tmp2 = x - a2;
        // cout << tmp1 << ' ' << tmp2 << endl;
        int ans = 0;
        if (tmp1 * tmp2 > 0) {
            flag++;
            ans = min(abs(tmp1), abs(tmp2));
        }
        int tmp3 = y - b1;
        int tmp4 = y - b2;
        // cout << tmp1 << ' ' << tmp2 << endl;
        if (tmp3 * tmp4 > 0) {
            flag++;
            ans = max(min(abs(tmp3), abs(tmp4)), ans);
        }

        if (flag == 2) {
            mx = min(abs(tmp1), abs(tmp2));
            my = min(abs(tmp3), abs(tmp4));
            ans = max(ans, mx + my);
        }
        cout << ans + 1 << endl;
    }
}