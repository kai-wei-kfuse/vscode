#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    ll n, k, b, s;
    while (t--) {
        cin >> n >> k >> b >> s;
        if (k * b <= s && s - n * (k - 1) <= k * b) {
            ll ans = s - b * k;
            ll sum = b * k;
            if (ans >= k - 1) {
                sum += k - 1;
                ans -= (k - 1);
            }
            for (int i = 1; i <= n; i++) {
                if (i == 1) {
                    cout << sum << ' ';
                } else {
                    if (ans >= k - 1) {
                        cout << k - 1 << ' ';
                        ans -= k - 1;
                    } else if (ans > 0) {
                        cout << ans << ' ';
                        ans = 0;
                    } else {
                        cout << '0' << ' ';
                    }
                }
            }
            cout << '\n';
        } else {
            cout << "-1" << '\n';
        }
    }
}