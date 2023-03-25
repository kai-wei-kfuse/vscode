#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int e, l, r, b;
        int ans1 = 0, ans2 = 0;
        cin >> e >> l >> r >> b;
        /*ans1 = e + l + r;
        if (b >= 1)
            ans1++;
        ans1 += b >= e ? e : b;
        // cout << ans1 << ' ';
        */
        ans1 = l + r;
        ans1 += b <= e ? e + b : 2 * e + 1;

        if (l == 0 && r == 0) {
            ans2 += e;
            if (b > 0)
                ans2++;
        } else {
            ans2 = max(l, r);
            ans2 += e;
        }
        cout << ans2 << ' ' << ans1 << '\n';
    }
}