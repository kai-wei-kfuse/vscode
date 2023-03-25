#include <algorithm>
#include <iostream>
using namespace std;

int a[55][55], dp1[55][55], dp1s[55][55], dp2[55][55], vis[55][55];

void find(int x, int y) {
    if (x == 1 && y == 1)
        return;
    vis[x][y] = 1;
    if (dp1s[x][y] == 1) {
        find(x, y - 1);
    } else if (dp1s[x][y] == -1) {
        find(x - 1, y);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            if (dp1[i - 1][j] + a[i][j] > dp1[i][j - 1] + a[i][j]) {
                dp1[i][j] = dp1[i - 1][j] + a[i][j];
                dp1s[i][j] = -1;
            } else {
                dp1[i][j] = dp1[i][j - 1] + a[i][j];
                dp1s[i][j] = 1;
            }
    }
    find(n, m);
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            cout << vis[i][j] << ' ';
            if (vis[i][j] == 0)
                dp2[i][j] =
                    max(dp2[i + 1][j] + a[i][j], dp2[i][j + 1] + a[i][j]);
        }
        cout << endl;
    }
    cout << dp1[n][m] + dp2[1][1];
}