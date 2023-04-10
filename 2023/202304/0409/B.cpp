#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > a(3, vector<int>(n + 1));
        if (n & 1) {
            a[1][1] = 2 * n;
            a[2][n] = 1;
            int cnt = 2;
            for (int i = 2; i <= n; i += 2) {
                a[2][i - 1] = cnt++;
                a[1][i] = cnt++;
            }
            for (int i = 3; i <= n; i += 2) {
                a[2][i - 1] = cnt++;
                a[1][i] = cnt++;
            }
        } else {
            a[1][1] = 2 * n;
            a[2][n] = 2 * n - 1;
            int cnt = 1;
            for (int i = 2; i <= n; i += 2) {
                a[2][i - 1] = cnt++;
                a[1][i] = cnt++;
            }
            for (int i = 3; i <= n; i += 2) {
                a[2][i - 1] = cnt++;
                a[1][i] = cnt++;
            }
        }
        for (int i = 1; i <= 2; i++) {
            for (int j = 1; j <= n; j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}