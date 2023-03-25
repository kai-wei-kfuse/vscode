#include <iostream>
typedef long long ll;
using namespace std;
ll ans[101];

void solve(ll x) {
    int cnt = 0;
    ll tmp2, tmp1 = 1;
    while (x > 0) {
        while (x % (tmp1 * 2) == 0)
            tmp1 *= 2;
        tmp2 = tmp1;
        while (x >= tmp2 * 3)
            tmp2 *= 3;
        x -= tmp2;
        ans[++cnt] = tmp2;
    }
    cout << cnt << endl;
    for (int i = 1; i <= cnt; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
int main() {
    freopen("distribution.in", "r", stdin);
    freopen("distribution.out", "w", stdout);
    int n;
    cin >> n;
    while (n--) {
        ll t;
        cin >> t;
        solve(t);
    }
}