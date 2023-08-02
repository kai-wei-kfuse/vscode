#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int n1 = 0, m1 = 0;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            n1 += tmp;
        }
        for (int i = 1; i <= m; i++) {
            int tmp;
            cin >> tmp;
            m1 += tmp;
        }
        if (n1 > m1) {
            cout << "Tsondu" << endl;
        } else if (n1 < m1) {
            cout << "Tenzing" << endl;
        } else {
            cout << "Draw" << endl;
        }
    }
}