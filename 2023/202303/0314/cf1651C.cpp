#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        long long mina1 = INT_MAX, mina2 = INT_MAX, minb1 = INT_MAX,
                  minb2 = INT_MAX;
        int a1=-1, a2=-1, b1=-1, b2=-1;
        for (int i = 1; i <= n; i++) {
            if (abs(b[i] - a[1]) < mina1) {
                mina1 = abs(b[i] - a[1]);
                a1 = i;
            }
            if (abs(b[i] - a[n])< mina2) {
                mina2 = abs(b[i] - a[n]);
                a2 = i;
            }
            if (abs(b[1] - a[i]) < minb1) {
                minb1 = abs(b[1] - a[i]);
                b1 = i;
            }
            if (abs(b[n] - a[i]) < minb2) {
                minb2 = abs(b[n] - a[i]);
                b2 = i;
            }
            // mina1 = min(abs(b[i] - a[1]), mina1);
            // mina2 = min(abs(b[i] - a[n]), mina2);
            // minb1 = min(abs(b[1] - a[i]), minb1);
            // minb2 = min(abs(b[n] - a[i]), minb2);
        }
        int ans = 0, res = INT_MAX;

        // ans = min(abs(a[1] - b[1]), mina1 + minb1) + min(abs(a[n] - b[n]), mina2 + minb2);
        //  if (a1 == 1 && b1 == 1) {
        //      ans+=min(mina1+mina2,)
        //  }
        //  if (a2 == n && b2 == n) {
        //      ans -= minb2;
        //  }
        vector<int> ve1{1, a1, n};
        vector<int> ve2{1, a2, n};
        for (auto i : ve1) {
            for (auto j : ve2) {
                ans = abs(a[1] - b[i]) + abs(a[n] - b[j]);
                if (i != 1 && j != 1) {
                    ans += minb1;
                }
                if (i != n && j != n) {
                    ans += minb2;
                }
                //cout << ans << endl;
                res = min(res, ans);
            }
        }
        cout << res << endl;
    }
}