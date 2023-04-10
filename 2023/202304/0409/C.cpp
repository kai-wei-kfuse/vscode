#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        vector<int> d(n + 1, 0);
        d[1] = ve[1];
        for (int i = 2; i <= n; i++) {
            d[i] = ve[i] - ve[i - 1];
            // cout << d[i] << ' ';
        }
        // cout << endl;
        int flag = 0;
        if (n & 1) {
        } else {
            int num = 0;
            for (int i = 2; i <= n; i += 2) {
                num += d[i];
            }
            if (num < 0) {
                flag = 1;
            }
        }
        if (flag) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}