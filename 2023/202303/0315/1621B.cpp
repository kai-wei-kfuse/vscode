#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num = 0, l = 0, r = 0x3f3f3f3f, res = 0;
        int ln = 0, rn = 0;
        int lastl, lastr;
        for (int i = 1; i <= n; i++) {
            int x, y, co;
            cin >> x >> y >> co; 
            if (num == 0) {
                l = x, r = y;
                res += co;
                num++;
                lastl = co, lastr = co;
            } else if (y > r && x > l) {
                r = y;
                res += co;
                if (num == 2) {
                    res -= lastr;
                } else {
                    num++;
                }
                lastr = co;
            } else if (x < l && y < r) {
                l = x;
                res += co;
                if (num == 2) {
                    res -= lastl;
                } else {
                    num++;
                }
                lastl = co;
            } else if ((y >= r && x < l)||(y > r && x <= l)) {
                l = x, r = y;
                if (num == 1) {
                    res -= lastl;
                } else {
                    res -= lastl;
                    res -= lastr;
                    num = 1;
                }
                lastl = lastr = co;
                res += co;
            } else if (x == l && y == r) {
                res = min(res, co);
            } else if (x == l) {
                if (lastl > co && num == 2) {
                    res -= lastl;
                    lastl = co;
                    res += co;
                }
            } else if (y == r) {
                if (lastr > co && num == 2) {
                    res -= lastr;
                    lastr = co;
                    res += co;
                }
            }
            cout << res << endl;
        }
    }
}