#include <iostream>
using namespace std;
int a[25], mp[25][25], dp[30], p[30];
void road(int x) {
    if (x == 0)
        return;
    road(p[x]);
    cout << x << ' ';
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = a[i];
    }
    int tmp;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> mp[i][j];
        }
    }
    int maxn = 0, maxi = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (mp[i][j]) {
                if (dp[j] < dp[i] + a[j]) {
                    dp[j] = dp[i] + a[j];
                    p[j] = i;
                }
            }
            if (maxn < dp[j]) {
                maxn = dp[j];
                maxi = j;
            }
        }
    }
    road(maxi);
    cout << '\n';
    cout << maxn;
}
