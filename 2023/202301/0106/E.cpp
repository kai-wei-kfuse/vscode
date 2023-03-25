#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
signed main() {
    IOS;
    int n, d, m, l;
    cin >> n >> d >> m >> l;
    int ans = -1;
    for (int i = 1; i <= (m + 10); i++) {
        if (i * d % m > l) {
            ans = i * d;
            break;
        }
    }
    if (ans != -1)
        cout << ans;
    else {
        cout << ((n - 1) * m + l) / d * d + d;
    }
}