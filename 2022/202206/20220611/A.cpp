#include <algorithm>
#include <iostream>
using namespace std;
char a[105], b[105];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
        }
        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);
        char flag;
        int ii = 1, jj = 1;
        if (a[1] <= b[1]) {
            while (ii < n && jj < m) {
                if (k < upper_bound(a + ii, a + n + 1, a[ii]) - a - ii) {
                    for (int i = ii; i <= k; i++) {
                        cout << a[i];
                    }
                    cout << ii << endl;
                    ii = ii + k;
                    cout << ii << endl;
                    cout << b[jj];
                    jj++;
                } else {
                    int tmp = upper_bound(a + ii, a + n + 1, a[ii]) - a;
                    for (int i = ii; i <= tmp; i++) {
                        cout << a[i];
                    }
                    ii += k;
                }
            }
        } else {
            while (ii < n && jj < m) {
                if (k < upper_bound(b + jj, b + n + 1, b[jj]) - b - jj) {
                    for (int i = jj; i <= k; i++) {
                        cout << b[i];
                    }
                    jj = jj + k;
                    cout << a[ii];
                    ii++;
                } else {
                    int tmp = upper_bound(b + jj, b + n + 1, b[jj]) - b;
                    for (int i = jj; i <= tmp; i++) {
                        cout << b[i];
                    }
                    jj += k;
                }
            }
        }
        cout << endl;
        /* for (int i = 1; i <= min(n, m); i += k) {
        }

        for (int i = 1; i <= n; i++) {
            cout << a[i];
        }
        cout << endl;
        for (int i = 1; i <= m; i++) {
            cout << b[i];
        }
        cout << endl; */
    }
}