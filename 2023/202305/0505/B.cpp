#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        int ans = 0;
        for (int i = 1; i * 2 <= n; i++) {
            ans = __gcd(ans, abs(ve[i] - ve[n - i + 1]));
        }
        cout << ans << endl;
    }
}