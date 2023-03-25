#include <algorithm>
#include <iostream>
using namespace std;
int dp[1005][1005], a[1005], val[1005];
int main() {
    int N, V;
    cin >> N >> V;
    for (int i = 1; i <= N; i++) {
        cin >> a[i] >> val[i];
    }
    for (int i = N; i >= 1; i--) {
        for (int j = 0; j <= V; j++) {
            dp[i][j] = dp[i + 1][j];
            if (j >= a[i]) {
                dp[i][j] = max(dp[i][j], dp[i + 1][j - a[i]] + val[i]);
            }
        }
    }
    int tmp = V;
    for (int i = 1; i <= N; i++) {
        if (tmp >= a[i] && dp[i][tmp] == dp[i + 1][tmp - a[i]] + val[i]) {
            cout << i << ' ';
            tmp -= a[i];
        }
    }
}