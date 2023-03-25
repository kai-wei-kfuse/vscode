#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        ll L = (ll)sqrt(max(l - 1, 1LL));
        ll R = (ll)sqrt(r);
        // cout << L << ' ' << R << endl;
        // cout << (l - L * L) / L + 1 << " " << (r - R * R) / R + 1 << endl;
        // ll ans = (R - 1) * 3 - (L - 1) * 3;
        //  cout << ans << endl;
        //  if (l != 1)
        //      ans -= ((l - L * L) / L + 1);
        //  if ((l - L * L) % L == 0)
        //      ans++;
        //  cout << ans + (r - R * R) / R + 1 << endl;
        ll ansl = (L)*3LL + (l - 1LL - L * L) / L + 1LL;
        ll ansr = (R)*3LL + (r - R * R) / R + 1LL;
        // cout << ansl << ' ' << ansr << endl;
        if (l == 1)
            cout << ansr << endl;
        else if (l > 1)
            cout << ansr - ansl << endl;
    }
}