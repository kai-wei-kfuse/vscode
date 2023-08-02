#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    if (n > m) {
        cout << -1 << endl;
        return 0;
    } else if (n == m) {
        if (n == 0) {
            cout << 0 << endl;
            return 0;
        }
        cout << 1 << endl << n << endl;
        return 0;
    } else {
        if ((m - n) & 1) {
            cout << -1 << endl;
        } else {
            if ((((m - n) / 2) ^ n) == m - (m - n) / 2) {
                cout << 2 << endl;
                // cout << (n ^ ((m - n) / 2)) << endl;
                cout << m - (m - n) / 2 << " " << (m - n) / 2 << endl;
            } else {
                cout << 3 << endl;
                cout << n << " " << (m - n) / 2 << " " << (m - n) / 2 << endl;
            }
        }
    }
}