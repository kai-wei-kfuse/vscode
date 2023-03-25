#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
int main() {
    int n, m;
    cin >> n >> m;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; i++) {
        int tmp;
        int last = 0;
        cin >> tmp;
        if (tmp == 1) {
            ll x, y;
            cin >> x >> y;
            if (last)
                sum -= a[x];
            else {
                sum -= last;
            }
            sum += y;
            a[x] = y;
            cout << sum << '\n';
        } else {
            ll x;
            cin >> x;
            last = x;
            sum = x * 1LL * n;
            cout << sum << '\n';
        }
    }
}