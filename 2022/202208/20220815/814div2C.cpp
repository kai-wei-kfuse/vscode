#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        int a, b, lun;
        // cout << n << q << endl;
        vector<vector<int>> ve(3, vector<int>(n + 1));
        cin >> a;
        int flag = 0;
        if (a != n) {
            for (int i = 2, cnt = 1; i <= n; i++, cnt++) {
                cin >> b;
                // cout << b;
                if (b != n && flag == 0) {
                    if (a > b) {
                        if (!ve[1][i - 1]) {
                            ve[1][i - 1] = cnt;
                            ve[2][i] = cnt;
                        } else {
                            ve[2][i] = cnt;
                        }
                    } else {
                        a = b;
                        if (!ve[1][i]) {
                            ve[2][i - 1] = cnt;
                            ve[1][i] = cnt;
                        } else {
                            ve[2][i - 1] = cnt;
                        }
                    }
                }
                if (b == n) {
                    flag = 1;
                    lun = i - 1;
                    if (!ve[1][i]) {
                        ve[2][i - 1] = cnt;
                        ve[1][i] = cnt;
                    } else {
                        ve[2][i - 1] = cnt;
                    }
                }
            }
        } else {
            for (int i = 2; i <= n; i++) {
                cin >> b;
            }
        }
        // cout << 'd' << lun << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 2; j++) {
                cout << ve[j][i] << ' ';
            }
            cout << endl;
        }
        for (int i = 1; i <= q; i++) {
            int j, k;
            cin >> j >> k;
            if (j == lun + 1)
                cout << max(k - lun, 0) << '\n';
            else if (ve[1][j] == 0) {
                cout << '0' << '\n';
            } else if (k >= lun)
                cout << ve[2][j] - ve[1][j] << '\n';
            else if (k >= ve[1][j] && k < lun)
                cout << k - ve[1][j] << '\n';
        }
    }
}