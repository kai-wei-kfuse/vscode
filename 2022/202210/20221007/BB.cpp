#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        ll L = (ll)sqrt(l);
        if (L * L > l)
            L--;
        ll R = (ll)sqrt(r);
        if (R * R > r)
            R--;
        ll ans = 0;
        if (L == R) {
            for (int i = 0; i < 3; i++) {
                if (l <= L * (L + i) && r >= L * (L + i))
                    ans++;
            }
        } else {
            ans = (R - L - 1LL) * 3;
            cout << ans << endl;
            for (int i = 0; i < 3; i++) {
                if (l <= L * (L + i) && r >= L * (L + i))
                    ans++;
            }
            for (int i = 0; i < 3; i++) {
                if (l <= R * (R + i) && r >= R * (R + i))
                    ans++;
            }
        }
        cout << R << " " << L << endl;
        cout << ans << endl;
    }
}