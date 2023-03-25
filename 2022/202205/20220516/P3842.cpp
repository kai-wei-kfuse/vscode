#include <iostream>
struct xx {
    int l, r;
} a[20005];
int dp[20005][5];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
    }
    dp[1][2] = a[1].r - 1;
    dp[1][1] = 2 * a[1].r - a[1].l - 1;
    int dist1 = 0, dist2 = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i].r - a[i - 1].l > 0)
            dist1 = a[i].r - a[i - 1].l + a[i].r - a[i].l + dp[i - 1][1];
        else
            dist1 = a[i - 1].l - a[i].l + dp[i - 1][1];
        if (a[i].r - a[i - 1].r > 0)
            dist2 = a[i].r - a[i - 1].r + a[i].r - a[i].l + dp[i - 1][2];
        else
            dist2 = a[i - 1].r - a[i].l + dp[i - 1][2];
        dp[i][1] = min(dist1, dist2) + 1;
        // cout << dist1 + 1 << ' ' << dist2 + 1 << endl;
        if (a[i - 1].l - a[i].l > 0) {
            dist1 = (a[i - 1].l - a[i].l) + a[i].r - a[i].l + dp[i - 1][1];
        } else
            dist1 = a[i].r - a[i - 1].l + dp[i - 1][1];
        if (a[i - 1].r - a[i].l > 0) {
            dist2 = (a[i - 1].r - a[i].l) + a[i].r - a[i].l + dp[i - 1][2];
        } else
            dist2 = a[i].r - a[i - 1].r + dp[i - 1][2];
        dp[i][2] = min(dist1, dist2) + 1
        //  cout << dist1 + 1 << ' ' << dist2 + 1 << endl;
    }

    cout << min(dp[n][1] + n - a[n].l, dp[n][2] + n - a[n].r);
}