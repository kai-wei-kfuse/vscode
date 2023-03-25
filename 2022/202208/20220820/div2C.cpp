#include <iostream>
using namespace std;
typedef long long ll;

ll a[100005];

int main() {
    int n, m;
    cin >> n >> m;
    ll x, y;
    ll ans = 0;
    if (n == 1) {
        while (m--) {
            cin >> x >> y;
            cout << '1' << '\n';
        }
    } else {
        for (ll i = 1, j = n; i <= n; i++, j--) {
            ans += i * j;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i >= 2) {
                if (a[i] == a[i - 1]) {
                    ans -= 1LL * (i - 1) * (n - (i - 1));
                }
            }
        }
        while (m--) {
            cin >> x >> y;
            if (a[x - 1] == a[x] && a[x - 1] != y) {
                ans += 1LL * (x - 1) * (n - (x - 1));
            }
            if (a[x + 1] == a[x] && a[x + 1] != y) {
                ans += 1LL * x * (n - x);
            }
            if (a[x - 1] != a[x] && a[x - 1] == y) {
                ans -= 1LL * (x - 1) * (n - (x - 1));
            }
            if (a[x + 1] != a[x] && a[x + 1] == y) {
                ans -= 1LL * x * (n - x);
            }
            a[x] = y;
            cout << ans << '\n';
        }
    }
}