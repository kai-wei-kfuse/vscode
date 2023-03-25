#include <algorithm>
#include <iostream>
using namespace std;
struct xx {
    int t, x, y;
} a[10005];
bool cmp(xx a, xx b) {
    return a.t < b.t;
}
int dp[10005];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i].t >> a[i].x >> a[i].y;
        dp[i] = 1;
    }
    sort(a + 1, a + m + 1, cmp);
    for (int i = 2; i <= m; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i].t - a[j].t <=
                    abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y) &&
                a[i].t - a[j].t != 0) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        // cout << dp[i] << endl;
        ans = max(dp[i], ans);
    }
    cout << ans;
}