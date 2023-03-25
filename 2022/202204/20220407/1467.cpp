#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll a[200050];
int main() {
    int p, d;
    cin >> p >> d;
    ll sum = 0;
    for (int i = 1; i <= p + d + 1; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + p + d + 2, greater<int>());
    ll ans = 0;
    if (d) {
        if (a[1] < 0) {
            for (int i = 2; i <= p + d + 1; i++) {
                ans += abs(a[i]);
            }
            ans += a[1];
        }
        if (a[1] >= 0 && a[p + d + 1] < 0) {
            for (int i = 1; i <= p + d + 1; i++) {
                ans += abs(a[i]);
            }
        }
        if (a[p + d + 1] >= 0) {
            for (int i = 1; i < p + d + 1; i++) {
                ans += a[i];
            }
            ans -= a[p + d + 1];
        }
    } else
        for (int i = 1; i <= p + d + 1; i++)
            ans += a[i];
    cout << ans;
}