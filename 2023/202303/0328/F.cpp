#include <bits/stdc++.h>
using namespace std;

int ans[1005][1005];

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(ans, 0, sizeof(ans));
        int n, k;
        cin >> n >> k;
        if (n & 1) {
            cout << "Impossible" << '\n';
        } else {
            if (k >= n) {
                cout << "Impossible" << '\n';
            } else {
                for (int k = 1; k < n; k++) {
                    if (k & 1) {
                        for (int i = 1, j = k; i <= n; i++, j++) {
                            if (i & 1) {
                                ans[k][i + 1] = j;
                            } else {
                                ans[k][i - 1] = j;
                            }
                            if (j == n) j = 0;
                        }
                    }
                }
                for (int k = 1; k < n; k++) {
                    if (k % 2 == 0) {
                        for (int i = 1; i <= n; i++) {
                            if (i & 1) {
                                ans[k][i] = ans[k + 1][i + 1];
                            } else {
                                ans[k][i] = ans[k + 1][i - 1];
                            }
                            // cout<<ans[k][i]<<' ';
                        }
                    }
                }
            }
            for (int i = 1; i <= k; i++) {
                for (int j = 1; j <= n; j++) {
                    cout << ans[i][j];
                    if (j != n)
                        cout << ' ';
                }
                cout << '\n';
            }
        }
    }
}