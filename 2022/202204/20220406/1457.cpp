#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;
ll a[1000005];
ll c[10000];
ll maxn = -0x7fffffff;
int main() {
    int n;
    cin >> n;
    int now = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        // a[i] += a[i - 1];
        if (i >= (1 << now))
            now++;
        c[now] += a[i];
    }
    // ll x = 1;
    ll ans = 1;
    // ll tmp = 1;
    // ll num = 0;
    // while (num < n) {
    //     num += tmp;
    //     tmp *= 2;
    // }
    // cout << num;
    // for (ll i = 1, j = 1; i < num; i += x, j++) {
    //     // maxn = max(maxn, a[i] - a[i - x]);
    //     if (maxn < a[i] - a[i - x]) {
    //         maxn = a[i] - a[i - x];
    //         ans = j;
    //     }
    //     x *= 2;
    // }
    for (int i = 0; i <= now; i++) {
        if (maxn < c[i]) {
            maxn = c[i];
            ans = i;
        }
    }
    cout << ans;
}