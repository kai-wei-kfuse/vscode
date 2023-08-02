#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> v;
        int flag = 0;
        for (int i = 1; i <= n; i *= a) {
            if ((n - i) % b == 0) {
                cout << "YES\n";
                flag = 1;
                break;
            }
            if (a == 1)
                break;
        }
        if (!flag)
            cout << "NO\n";
    }
}