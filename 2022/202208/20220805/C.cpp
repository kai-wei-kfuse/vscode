#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > a(3, vector<int>(n + 2)), b(3, vector<int>(n + 2)),
            dp1(3, vector<int>(n + 2)), dp2(3, vector<int>(n + 2)),
            st(3, vector<int>(n + 2));
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                st[i][j] = 0;
            }
        }
        for (int i = 0; i < 2; i++) {
            dp1[i][n + 1] = dp2[i][n + 1] = -1e18;
            for (int j = n; j >= 1; j--) {
                dp1[i][j] = max(dp1[i][j + 1], a[i][j] + j);
                dp2[i][j] = max(dp2[i][j + 1], a[i][j] - j);
            }
        }
        int x = 0, y = 1;
        int t = 0;  //蛇形时间
        st[0][1] = 1;
        int ans = 1e18;
        while (1) {
            if (!st[x ^ 1][y]) {
                int tmp = max(t + n - y, dp2[x][y + 1] + 1 + n);
                ans = min(ans, max(tmp + n - y + 1, dp1[x ^ 1][y] - y + 1));
                x ^= 1;
            } else
                y++;
            if (y > n)
                break;
            st[x][y] = 1;
            t = max(t + 1, a[x][y] + 1);
        }
        cout << min(t, ans) << '\n';
    }
}